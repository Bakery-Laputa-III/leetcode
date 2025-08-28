#!/usr/bin/env python3
import os
import json
import subprocess
from pathlib import Path

def main():
    # 配置文件和目录（使用相对路径）
    script_dir = os.path.dirname(os.path.abspath(__file__))
    clang_format_file = os.path.join(script_dir, ".clang-format")
    source_dir = os.path.join(script_dir, "100hot")
    record_file = os.path.join(script_dir, "format_record.json")
    
    # 检查.clang-format文件是否存在
    if not os.path.exists(clang_format_file):
        print(f"错误: 找不到.clang-format文件: {clang_format_file}")
        return
    
    # 检查源目录是否存在
    if not os.path.exists(source_dir):
        print(f"错误: 找不到源目录: {source_dir}")
        return
    
    # 加载已格式化文件记录（包含文件修改时间）
    formatted_records = {}
    if os.path.exists(record_file):
        try:
            with open(record_file, 'r', encoding='utf-8') as f:
                data = json.load(f)
                formatted_records = data.get('formatted_records', {})
        except (json.JSONDecodeError, IOError) as e:
            print(f"警告: 无法读取记录文件 {record_file}: {e}")
            formatted_records = {}
    
    # 获取所有cpp文件
    cpp_files = []
    for file in os.listdir(source_dir):
        if file.endswith('.cpp'):
            cpp_files.append(os.path.join(source_dir, file))
    
    if not cpp_files:
        print("没有找到.cpp文件")
        return
    
    print(f"找到 {len(cpp_files)} 个cpp文件")
    
    # 格式化文件
    newly_formatted = []
    for cpp_file in cpp_files:
        file_name = os.path.basename(cpp_file)
        file_stat = os.stat(cpp_file)
        current_mtime = file_stat.st_mtime
        
        # 检查文件是否需要重新格式化
        if file_name in formatted_records:
            recorded_mtime = formatted_records[file_name].get('mtime', 0)
            if current_mtime <= recorded_mtime:
                print(f"跳过未修改文件: {file_name}")
                continue
            else:
                print(f"检测到文件已修改，重新格式化: {file_name}")
        else:
            print(f"正在格式化新文件: {file_name}")
        
        try:
            # 使用clang-format格式化文件
            result = subprocess.run(
                ['clang-format', '-style=file', '-i', cpp_file],
                capture_output=True,
                text=True,
                cwd=script_dir
            )
            
            if result.returncode == 0:
                # 获取格式化后的文件修改时间
                formatted_mtime = os.stat(cpp_file).st_mtime
                formatted_records[file_name] = {
                    'mtime': formatted_mtime,
                    'formatted_at': str(formatted_mtime)
                }
                newly_formatted.append(file_name)
                print(f"✓ 成功格式化: {file_name}")
            else:
                print(f"✗ 格式化失败: {file_name}")
                print(f"错误: {result.stderr}")
                
        except FileNotFoundError:
            print("错误: 未找到clang-format命令，请确保已安装clang-format")
            return
        except Exception as e:
            print(f"✗ 格式化时发生错误: {file_name} - {e}")
    
    # 保存记录
    try:
        record_data = {
            'formatted_records': formatted_records,
            'last_updated': str(Path().stat().st_mtime)
        }
        
        with open(record_file, 'w', encoding='utf-8') as f:
            json.dump(record_data, f, indent=2, ensure_ascii=False)
        
        print(f"\n格式化完成!")
        print(f"新格式化文件: {len(newly_formatted)} 个")
        print(f"总计已格式化文件: {len(formatted_records)} 个")
        print(f"记录已保存到: {record_file}")
        
    except IOError as e:
        print(f"警告: 无法保存记录文件 {record_file}: {e}")

if __name__ == "__main__":
    main()
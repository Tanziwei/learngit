#!/bin/bash
# usage_example.sh - Example script showing how to use the C to Excel generator

echo "C函数文档生成器使用示例"
echo "========================"
echo ""

echo "1. 检查当前目录中的.c文件:"
ls -la *.c
echo ""

echo "2. 运行文档生成器:"
python3 c_to_excel.py
echo ""

echo "3. 检查生成的Excel文件:"
if [ -f "function_documentation.xlsx" ]; then
    echo "✓ Excel文件已成功生成: function_documentation.xlsx"
    ls -la function_documentation.xlsx
else
    echo "✗ Excel文件生成失败"
fi
echo ""

echo "4. 验证Excel内容:"
python3 test_excel.py | tail -5
echo ""

echo "使用完成！您可以用Excel打开 function_documentation.xlsx 文件查看结果。"
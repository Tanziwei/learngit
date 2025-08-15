# C函数文档生成器

这个Python脚本可以读取目录下的.c文件，解析函数注释，并生成包含函数文档的Excel文件。

## 功能特性

- 自动扫描目录中的所有.c文件
- 解析函数注释中的结构化信息
- 生成包含以下列的Excel文件：
  1. **设计ID** - 从`@note Function ID: XXX`注释中提取
  2. **接口名称** - 函数名
  3. **语法** - 完整的函数签名
  4. **参数** - 参数详细信息（参数名、输入/输出、值域范围、初始值、说明）
  5. **返回值** - 返回值信息（类型、值域范围、说明）

## 使用方法

### 1. 安装依赖

```bash
pip install openpyxl
```

### 2. 运行脚本

将脚本放在包含.c文件的目录中，然后运行：

```bash
python3 c_to_excel.py
```

脚本会：
- 自动扫描当前目录中的所有.c文件
- 解析函数注释
- 生成`function_documentation.xlsx`文件

## 注释格式要求

为了正确解析函数信息，.c文件中的函数注释需要遵循以下格式：

```c
/**
 * @brief 函数简要描述
 * @note Function ID: DES_LIN_API_XXX
 * @param 参数名 参数描述
 *        输入/输出: 输入|输出
 *        值域范围: 参数的值域范围
 *        初始值: 参数的初始值
 *        说明: 参数的详细说明
 * @return 返回类型 返回值描述
 *         值域范围: 返回值的值域范围
 *         说明: 返回值的详细说明
 */
返回类型 函数名(参数列表);
```

### 示例：

```c
/**
 * @brief Initialize the SENT HAL module
 * @note Function ID: DES_LIN_API_107
 * @param SentModuleConfig Pointer to module configuration
 *        输入/输出: 输入
 *        值域范围: Valid pointer to configuration structure
 *        初始值: NULL
 *        说明: Configuration structure for SENT module initialization
 * @return Sent_ChannelStatusType Status of initialization
 *         值域范围: SENT_OK, SENT_ERROR, SENT_BUSY
 *         说明: Returns the status of the initialization operation
 */
void Sent_Hal_InitModule(Sent_ModuleConfigType * SentModuleConfig);
```

## 输出格式

生成的Excel文件包含以下列：

| 设计ID | 接口名称 | 语法 | 参数 | 返回值 |
|--------|----------|------|------|--------|
| DES_LIN_API_107 | Sent_Hal_InitModule | void Sent_Hal_InitModule(...) | 参数名：SentModuleConfig<br>输入/输出：输入<br>值域范围：...<br>初始值：...<br>说明：... | 类型：Sent_ChannelStatusType<br>值域范围：...<br>说明：... |

## 文件说明

- `c_to_excel.py` - 主脚本文件
- `sample_module.c` - 示例C文件，展示正确的注释格式
- `test_excel.py` - 测试脚本，用于验证生成的Excel内容
- `function_documentation.xlsx` - 生成的Excel文档文件

## 注意事项

1. 脚本会尝试使用UTF-8编码读取文件，如果失败会尝试GBK编码
2. 只有包含`@note Function ID:`注释的函数会被解析
3. 函数签名需要紧跟在注释块之后
4. 参数和返回值的详细信息需要按照指定格式编写

## 故障排除

如果遇到问题：

1. 确保.c文件中的注释格式正确
2. 检查函数签名是否紧跟在注释后面
3. 确保安装了openpyxl库
4. 检查文件编码是否为UTF-8或GBK
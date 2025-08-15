/**
 * @file edge_cases.c
 * @brief Test file for edge cases
 */

// Function without proper Function ID comment - should be ignored
void IgnoredFunction(void)
{
    // This function should not appear in the Excel
}

/**
 * @brief Function with minimal documentation
 * @note Function ID: EDGE_CASE_001
 */
void MinimalFunction(void)
{
    // Minimal function with no parameters or return documentation
}

/**
 * @brief Function with complex return type
 * @note Function ID: EDGE_CASE_002
 * @param data Input data pointer
 *        输入/输出: 输入
 *        值域范围: Valid pointer
 *        初始值: NULL
 *        说明: Data to process
 * @return const volatile uint32* Pointer to result
 *         值域范围: Valid pointer or NULL
 *         说明: Pointer to processed data result
 */
const volatile uint32* ComplexReturnFunction(const uint8* data)
{
    return NULL;
}
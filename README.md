# LeetCode

## 001 . 两数之和

&emsp; &emsp; 方法1：先排序，然后选出和为目标值的数字，再返回原数组查找<br/>
&emsp; &emsp; 方法2：使用哈希表，然后遍历数组，看是否存在 target - left 的值

## 002 . 两数相加

&emsp; &emsp; 先创建一个空节点，指向真正的用来指向真正的头结点，并用来保证代码的一致性。<br/>
&emsp; &emsp; 通过一个临时值记录下一位是否进1，以保证下一位不会被遗漏。

## 003 . 无重复字符的最长子串

&emsp; &emsp; 通过 int 数组充当 hash 表，以判断前面出现的同样的字符的下标

## 004 . 寻找两个正序数组的中位数

&emsp; &emsp; 方法1：合并两个数组遍历，找到下标为 (m + n) / 2 和 (m + n) / 2 + 1 的值。时间复杂度 O(m + n)，空间复杂度 O(m + n)<br/>
&emsp; &emsp; 方法2：动态二分查找，由于两个数组都已排序，所以其中的数都在中位数两侧，因此在两个数组可分别找到一个位置，该位置左边与右边的元素个数相同或相差 1，同时在两个数组该位置左侧的元素都比右边的元素要小，找出该位置即可。时间复杂度 O(log(m + n))，空间复杂度 O(1)。

## 005 . 最长回文子串

&emsp; &emsp; 方法1：中心扩展法。以中心向两端进行比较。时间复杂度 O(n^2)，空间复杂度 O(1)<br/>
&emsp; &emsp; 方法2：Manacher。中心扩展的同时，根据现中心给右侧的元素赋予回文长度。当右侧回文长度超过当前回文串的长度时，以该元素为中心进行回文检查。

## 006 . Z 字形变换

&emsp; &emsp; 找规律

## 007 . 整数反转

&emsp; &emsp; 注意可能会导致超出有效范围的情况。与 MAX_INT/10 和 MIN_INT/10 作对比。以及当已经转移的位数为 30 且当前值等于  MAX_INT/10 或 MIN_INT/10 时，最后一位与 7 进行对比。

## 008 . ATOI

&emsp; &emsp; 各种特殊情况。先除去前面的空格，然后判断是否存在符号，然后判断前面是否为 0

## 009 . 回文数

&emsp; &emsp; 用一个数组存储各个位的数字，然后两边进行对比

## 010 . 正则表达式匹配

&emsp; &emsp; 动态规划。构建 n * m 的数组，其中 dp[i][j] 表示正则表达式 regular 前 i 个字符能否与前 j 个待匹配字符串 target 匹配。<br/>
&emsp; &emsp; dp[0][0] 表示 0 个正则表达式与 0 个目标字符串匹配为 true。<br/>
&emsp; &emsp; 当 regular[j] 为 * 时，dp[i][j] 为 dp[i][j-2] 与 target[i] == regular[j - 1] 或 regular[j - 1] == '.' 时， regular[i][j] 为 true。<br/>
&emsp; &emsp; 最后 dp[n][m] 即为结果。<br/>
&emsp; &emsp; 时间复杂度 O(n * m)，空间复杂度 O(n * m)。

## 011 . 盛最多水的容器

&emsp; &emsp; 双指针法。在两侧同时往中间靠拢，当前的盛水量等于较低的边乘以宽度，随后较短的一侧往中间靠拢以查找是否有更大的值。<br/>
&emsp; &emsp; 时间复杂度 O(n)，空间复杂度 O(1)。

## 012 . 整数转罗马数字

&emsp; &emsp; 通过键值表反向排序，同时插入特殊的如4、9等键值，然后依次相减直至获得最终结果。<br/>
&emsp; &emsp; 时间复杂度 O(logn)，空间复杂度 O(1)。n为数字位数。

## 013 . 罗马数字转整数

&emsp; &emsp; 通过键值表反向排序，同时插入特殊的如4、9等键值，然后依次相减直至获得最终结果。<br/>
&emsp; &emsp; 时间复杂度 O(logn)，空间复杂度 O(1)。n为数字位数。

## 014 . 最长公共前缀

&emsp; &emsp; 字符串同一位进行匹配即可。<br/>
&emsp; &emsp; 时间复杂度 O(logn)，空间复杂度 O(1)。

## 015 . 三数之和

&emsp; &emsp; 先对原数组进行排序，然后通过双指针法找到结果。通过排除重复元素减少重复计算。<br/>
&emsp; &emsp; 由于需要记录不重复的组个数，时间复杂度 O(n^2)，空间复杂度 O(logn)。

## 016 . 最接近的三数之和

&emsp; &emsp; 先对原数组进行排序，然后通过双指针法找到结果。每次用当前三个数的和与目标值的差值的绝对值，与之前获得的差值进行比较，较小则替换。<br/>
&emsp; &emsp; 时间复杂度 O(n^2)，空间复杂度 O(1)。

## 017 . 电话号码的字母组合

&emsp; &emsp; 创建字典，然后使用数组存储上一次遍历的值，下一次遍历时遍历该数组然后进行字符串的组合即可。<br/>
&emsp; &emsp; 时间复杂度 O(3^n), 空间复杂度 O(3^n)。

## 018 . 四数之和

&emsp; &emsp; 类似于之前三数之和做法。<br/>
&emsp; &emsp; 时间复杂度 O(n^3)，空间复杂度 O(logn)。

## 019 . 删除链表的倒数第 N 个结点

&emsp; &emsp; 双指针法，一个指针移动了 N 次后，第二个指针才开始移动。<br/>
&emsp; &emsp; 同时，使用一个前置节点，以头结点作为该前置节点的下一个节点，返回结果时直接返回前置节点的子结点以减少特殊条件的判断。<br/>
&emsp; &emsp; 时间复杂度 O(n)，空间复杂度 O(1)。<br/>

## 020 . 有效的括号

&emsp; &emsp; 使用栈，当左括号时入栈，右括号时出栈然后判断是否是对应的括号。<br/>
&emsp; &emsp; 通过一个数组作为 HashMap，通过该数组判断括号是否匹配。<br/>
&emsp; &emsp; 时间复杂度 O(n)，空间复杂度 O(n)。

## 021 . 合并两个有序链表

&emsp; &emsp; 使用一个前置节点，以头结点作为该前置节点的下一个节点，返回结果时直接返回前置节点的子结点以减少特殊条件的判断。<br/>
&emsp; &emsp; 时间复杂度 O(n)，空间复杂度 O(1)。

## 022 . 括号生成

&emsp; &emsp; 迭代，用左括号以及右括号剩余个数作为参数，当两个个数一致时将生成的字符串放入结果中。<br/>
&emsp; &emsp; 该问题可视为入栈出栈问题，时间复杂度为卡特兰数通项 O(4^n/n^(1/2))，空间复杂度为递归深度 O(n)。

## 023 . 合并K个升序链表

&emsp; &emsp; 先构造一个小堆顶，堆的长度为非空链表个数 + 1, 加 1 为了添加一个零号节点，用于方便后续调整的判断。将每个链表的首元素放进去，初始化堆之后，每次取堆的下标为 1 的元素。如果该元素存在下一个节点，则将该下标的元素赋值为该下一个节点，同时对堆进行调整。若不存在下一个节点，则堆的长度 -1，同时将最后一个元素赋值给第一个元素，然后进行调整，直到堆的长度为 1，即零号节点则全部元素获取完毕。<br/>
&emsp; &emsp; 时间复杂度 O(nlog(m))，空间复杂度为 O(m)。n 为所有链表总元素个数，m 为链表数组的链表元素个数。

## 024 . 两两交换链表中的节点

&emsp; &emsp; 日常用一个空置节点减少判断。然后分别记录下交换后的后一个节点以作为下一次节点交换的前节点。<br/>
&emsp; &emsp; 时间复杂度 O(n)，空间复杂度 O(1)。

## 025 . K 个一组翻转链表

&emsp; &emsp; 日常用一个空置节点减少判断。然后可以转过来想，相当于把后面的节点都插入到第一个节点，然后将该节点的首位置进行重置，只需要声明两个指针即可完成工作。<br/>
&emsp; &emsp; 时间复杂度 O(n)，空间复杂度 O(1)。

## 026 . 删除有序数组中的重复项

&emsp; &emsp; 设置两个指针 left, right，初始值都为 1，当 nums[right - 1] == nums[right] 时，将 nums[left] 赋值为 nums[right] 同时 left++。<br/>
&emsp; &emsp; 时间复杂度 O(n)，空间复杂度 O(1)。

## 027 . 移除元素

&emsp; &emsp; 双指针，然后左指针相等时，将其与右指针的值交换，同时右指针不能为相同的元素值，并且记录相同元素个数，然后返回数组长度减去相同元素个数。<br/>
&emsp; &emsp; 时间复杂度 O(n)，空间复杂度 O(1)。

## 028 . 实现 strStr

&emsp; &emsp; KMP，先构造 KMP 数组，该数组记录了每次重新匹配开始的位置，避免了暴力搜索的多余的匹配。<br/>
&emsp; &emsp; 时间复杂度 O(n)，空间复杂度 O(m)，n 为源字符串 haystack 的长度，m 为目标字符串 needle 的长度。

## 029 . 两数相除

&emsp; &emsp; 每次使用移位来进行幂级别的商。由于 LeetCode 上的 C++ 编译器不支持负数的位运算以及对 INT32_MIN 的取负操作，所以使用 unsigned int 并且使用位运算将负数转换为 unsigned 的正数，并在返回时再进行一次位运算返回负数。<br/>
&emsp; &emsp; 时间复杂度 O(logn)，空间复杂度 O(1)。n 为 dividend/divisor。

## 030 . 串联所有单词的子串

&emsp; &emsp; 建立哈希表，分别记录每个单词需要出现的次数，每个单词已经出现的下标，每次出现单词的下标与对应的单词。当上一轮循环没有找到到此且这轮循环找到单词时，直接插入哈希表。如果上一轮循环找到，这轮找到，且出现次数未超出限制，则直接插入，否则需要去除该单词第一次出现的下标前的信息。<br/>
&emsp; &emsp; 循环 K 次滑动窗口，K为单词的长度，由于单词长度一致，所以窗口每次循环移动为 K。一轮窗口循环后下标 +1 再执行循环，直至 K 次循环完成。<br/>
&emsp; &emsp; 时间复杂度 O(Kn)，n 为字符串 s 的长度。空间复杂度 O(m)，m 为字符串组 words 的字符串个数。

## 031 . 下一个排列

&emsp; &emsp; 题目要求原地修改，空间复杂度 O(1)，只需两轮反向筛选的循环然后对替换过后的位数进行堆排序即可。

## 032 . 最长有效括号

&emsp; &emsp; 方法 1：两轮遍历，从左到右进行遍历，若左括号与右括号数量相同，则更新最长括号数，若右括号个数大于左括号，则括号数置零。同理从右到左遍历。综合两次遍历的结果获得最终的长度。时间复杂度 O(n)，空间复杂度 O(1)。<br/>
&emsp; &emsp; 方法 2：使用栈，先放入 -1，然后遍历字符串，如果为左括号则入栈，右括号则出栈。出栈时判断若当前栈为空，则放入当前下标作为下一次计算长度的初始值；若不为空则使用当前下标减去栈顶的值作为当前获取的有效括号长度。时间复杂度 O(n)，空间复杂度 O(n)。<br/>
&emsp; &emsp; 方法 3：动态规划，若当前为右括号，则判断是否 i - dp[i-1] - 1 >= 0，若为真，则判断 i - dp[i-1] - 1 在字符串中是否为左括号，若为左括号，当前的值为 2 + dp[i-1]，且判断左括号前一个下标 i - dp[i-1] - 1 - 1 >= 0，若为真，则当前的值为 2 + dp[i-1] + dp[dp[i-1] - 1 - 1]，最后遍历动态规划数组找到最大长度。时间复杂度 O(n)，空间复杂度 O(n)。

## 033 . 搜索旋转排序数组

&emsp; &emsp; 变种二分查找，先找到旋转中心，然后根据下标为 0 的值和旋转中心的值做对比决定二分查找的区域。<br/>
&emsp; &emsp; 时间复杂度 O(logn)，空间复杂度 O(1)。

## 034 . 在排序数组中查找元素的第一个和最后一个位置

&emsp; &emsp; 变种二分查找，先找到等于目标值的下标，然后在该下标左右再分别进行二分查找，找到 nums[n] == target && nums[n - 1] != target 以及 nums[m] == target && nums[m + 1] != target 的位置。<br/>
&emsp; &emsp; 时间复杂度 O(logn)，空间复杂度 O(1)。

## 035 .  搜索插入位置

&emsp; &emsp; 变种二分查找，先找到等于目标值的下标，若找不到则返回 left 即为插入值。<br/>
&emsp; &emsp; 时间复杂度 O(logn)，空间复杂度 O(1)。

## 036 . 有效的数独

&emsp; &emsp; 遍历数组，依次判断横竖以及实线内是否有重复元素即可。<br/>
&emsp; &emsp; 因为 n 为固定值，时间复杂度 O(1)，空间复杂度 O(1)。

## 037 . 解数独

&emsp; &emsp; 递归，深度优先遍历。<br/>
&emsp; &emsp; 先统计各行各列以及各个九宫格中已有的数字，同时当不存在数字时，将其位置放入一个列表中，以减少后续的遍历。然后对该位置列表进行遍历，并进行 dfs，递归条件为遍历 1-9，当其不在行、列及九宫格中时，将其在各行、各列以及九宫格中赋值，进行下一层 dfs，然后在 dfs 结束时，根据标志位判断是否已赋值元素个数是否等于待赋值元素个数，若相等，则将数独中的元素赋值，各层 dfs 结束。否则则将其在各行、各列以及九宫格中的值重置。<br/>
&emsp; &emsp; 时间复杂度 O(n^9)，空间复杂度 O(n)，n 为数独中的空白元素个数。

## 038 . 外观数列

&emsp; &emsp; 理解题意后进行递归即可<br/>
&emsp; &emsp; 由于需要进行 n 次递归，同时每次迭代使用的都是先前的结果。时间复杂度 O(n)，空间复杂度 O(1)。

## 039 . 组合总和

&emsp; &emsp; 递归。递归的函数参数分别为原数组的引用 candidates，当前已组合元素数组的引用 currentResult (用来避免值传递的内存以及时间消耗)，当前遍历开始的下标 startIndex，当前已组合元素数组的总值 currentSum，以及目标值 target。<br/>
&emsp; &emsp; 当总和等于目标值时，拷贝 currentResult 放入总结果中，移除 currentResult 的最后一个元素，直接返回。<br/>
&emsp; &emsp; 从 startIndex 开始遍历 candidates，如果 candidates[i] + currentSum <= target，则进行下一次迭代。否则，移除 currentResult 的最后一个元素然后返回。<br/>
&emsp; &emsp; 若遍历完 candidates 数组没有返回，即没有出现 candidates[i] + currentSum > target 的情况，则需要移除 currentResult 的最后一个元素供上一层的下次迭代使用。<br/>
&emsp; &emsp; 由于每个元素可以被使用的次数未知，最差要进行 n * 2^n 次方的递归，时间复杂度 O(n * 2 ^ n)，空间复杂度 O(n)。

## 040 . 组合总和

&emsp; &emsp; 与 39 题思路一致，但要排除重复元素且每个元素只能使用一次，因此下轮迭代的遍历的下标要从 + 1 开始，且需要通过与 15 题类似的思路排除重复元素即可。<br/>
&emsp; &emsp; 时间复杂度 O(n^n)，空间复杂度 O(n)。

## 041 . 缺失的第一个正数

&emsp; &emsp; 每次将 nums[i] 与 nums[nums[i]-1] 的元素进行交换，确保每个合法数字位于其下标上。然后遍历数组，下标为 i 的元素不等于 i + 1，则返回 i + 1 即为结果。<br/>
&emsp; &emsp; 时间复杂度 O(n)，空间复杂度 O(1)。

## 042 . 接雨水

&emsp; &emsp; 方法 1：观察图像可知，每个接水的面积都经历一个 height 值变小后变大的过程，使用栈，每次高度下降时将高度差以及下标入栈，每次高度上升时，高度差若小于栈顶高度，则记录上升高度到起始位置之间的面积，同时栈顶高度需要减去当前高度。若大于等于栈顶高度，则计算完面积后出栈。计算到最后获得最终结果。<br/>
&emsp; &emsp; 方法 1 时间复杂度 O(n)，空间复杂度 O(m)，n 为 height 的元素个数，m 为柱子的最高高度。<br/>
&emsp; &emsp; 方法 2：使用双指针法，确保每根能接水的柱子的左侧柱子的最高高度小于右侧柱子的最高高度，然后对该柱子的高度进行相加得到最终结果。<br/>
&emsp; &emsp; 方法 2 时间复杂度 O(n)，空间复杂度 O(1)。

## 043 . 字符串相乘

&emsp; &emsp; 根据分析可知，两个数字相乘会有 num1Size + num2Size - 1 个对应位数相乘的结果，但保留两个数组第一位相乘时可能导致的进位，因此使用长度 num1Size + num2Size 的数组保存位数相乘的结果，位数相乘结果放在 i + j +1 的位置。然后对该存放结果的数组进行处理即可得到最后的结果。但需要注意对前几位为 0 的情况需要进行特殊处理，跳过所有为 0 的位数，若最终跳过的位数等于结果数组长度则返回 0，否则从该位数开始遍历得到结果。<br/>
&emsp; &emsp; 时间复杂度 O(n * m), 空间复杂度 O(n + m)。

## 044 . 通配符匹配

&emsp; &emsp; 方法 1：类似于第 10 题，使用动态规划即可。<br/>
&emsp; &emsp; 当遍历到通配符 * 时，当前的值相当于前一个正则长度值是否匹配、前一个正则长度以及前一个字符串是否匹配，以及前一个字符串与当前正则长度是否匹配的或集。<br/>
&emsp; &emsp; 否则则判断前一个字符串长度和正则长度是否匹配，且当前是否为 ? 或字符是否相等即可。<br/>
&emsp; &emsp; 时间复杂度 O(n * m)，空间复杂度 O(n * m)。<br/>
&emsp; &emsp; 方法 2：贪心算法<br/>
&emsp; &emsp; 每次匹配到 * 时，记录下当前位置 sRecord 和 pRecord，如果接下来的字符串匹配失败，判断是否可以回溯之前位置，不可以则匹配失败。可以则 ++sRecord 并将 sRecord 的值赋给 sLeft 继续下一次遍历。遍历到最后，判断 pLeft 与 pRight 之间是否全是 * 号，不是则返回 false。 <br/>
&emsp; &emsp; 最差时间复杂度 O(n * m)，空间复杂度 O(1)。但当字符串 s 和 p 随机时，即 p 不会出现大量间断 * 号时，可以很快的结束遍历，平均起来时间复杂度远小于 O(n * m)。

## 045 . 跳跃游戏 II

&emsp; &emsp; 经典贪心算法题目。<br/>
&emsp; &emsp; 方法 1：从后往前遍历，使用栈存放能跳到该位置的下标，若栈的数目在遍历时发生过变化，出栈，跳跃数 +1；否则则出栈，同时跳跃数 -1，直到找到 0 下标即可。<br>
&emsp; &emsp; 由于每次需要从后往前遍历，同时存在回溯的可能性，时间复杂度 O(n^2)，空间复杂度 O(n)。<br/>
&emsp; &emsp; 方法 2：从前往后遍历，找到一个能跳到最远位置的格子作为下一次跳跃的下标。<br/>
&emsp; &emsp; 由于题目保证了一定能跳到最后的格子，所以能跳到最远位置的格子一定是最优的格子。因此减少了需要作为回溯的遍历的次数，时间复杂度 O(n)，空间复杂度 O(1)。

## 046 . 全排列

&emsp; &emsp; 类似于第 39 题，使用回溯以及递归的做法。<br/>
&emsp; &emsp; 时间复杂度 O(n * n!)，空间复杂度为递归深度以及存放当前结果个数 n 总和为 O(n)。

## 047 . 全排列 II

&emsp; &emsp; 46 题进阶版，使用回溯以及递归的做法。<br/>
&emsp; &emsp; 方法 1：同时每一层递归需要使用哈希表记录当前层已经找过的数字，如果有重复则进行下一次遍历。<br/>
&emsp; &emsp; 时间复杂度 O(n * n!)，空间复杂度为递归深度以及存放结果个数 n 以及各层需要存放当前层已经遍历过的数字，最差情况为 1 + 2 + ··· + n，总和为 O(n^2)。<br/>
&emsp; &emsp; 方法 2：在递归条件前更改判断条件，确保每一层使用重复数字时是从左到右使用。<br/>
&emsp; &emsp; 时间复杂度 O(n * n!)，空间复杂度为递归深度以及存放结果个数 n，总和为 O(n)。<br/>

## 048 . 旋转图像

&emsp; &emsp; 找到第 i 行，第 i 列，第 length - 1 - i 行，第 length - 1 - i 列的元素的对应关系即可。原地交换元素。<br/>
&emsp; &emsp; 时间复杂度 O(n^2)，空间复杂度 O(1)。n 为行数。

## 049 . 字母异位词分组

&emsp; &emsp; 建立字符串映射到下标的哈希表，遍历字符串，同时用一个临时字符串记录当前字符串，然后对临时字符串进行排序，然后查看是否存在在哈希表中即可。<br/>
&emsp; &emsp; 时间复杂度 O(n^m)，空间复杂度 O(n^m)。n 为字符串个数，m 为字符串的字母数。

## 050 . Pow(x, n)

&emsp; &emsp; 类似于 29 题两数相除的做法。基于 x 不断乘以 2 直到其比 n 要大，然后再用 n 减去以乘以的数字。如果是负号则用 1 除以其正数幂即可。同时由于不像 29 题存在不准使用大数的限制，使用大数强制转换 n 以方便处理。同时需要对 x 的幂可能出现无穷小以及无穷大的情况进行处理。<br/>
&emsp; &emsp; 官方做法：对 n 不断 %2 进行判断，若等于 1，则用结果乘以当前幂，否则当前幂乘以当前幂，且 n/=2。<br/>
&emsp; &emsp; 时间复杂度 O(logn)，空间复杂度 O(1)。n 为参数 n 的大小。

## 051 . N 皇后

&emsp; &emsp; 类似于 37 题解数独的做法进行递归即可。同时由于棋盘的对称性，只需要遍历一半的棋盘格，然后进行对称计算得到另一半即可。<br/>
&emsp; &emsp; 由于需要遍历 n! 次，然后每个元素赋值后需要给纵向、下方斜向的元素标志，每个元素需要执行 (2 * (n - 1) + (n - 2)…… + 1) / n = O(n) 次，因此时间复杂度为 O(n! * n)，然后记录每个皇后下方以及斜下方状态的数组，空间复杂度为 O(n ^ 2)。<br/>
&emsp; &emsp; 官方做法，使用哈希表然后通过下标判断之前某个是否有皇后，时间复杂度为 O(n!)，空间复杂度为 O(n)。

## 052 . N 皇后 II

&emsp; &emsp; 第 51 题的简化版，省去了记录结果的步骤。但仍需要记录每个皇后下方以及斜下方的状态。<br/>
&emsp; &emsp; 时间复杂度 O(n!)，空间复杂度 O(n ^ 2)。

## 053 . 最大子序和

&emsp; &emsp; 经典贪心题。相加至当前值小于零时，将当前总和置零即可。<br/>
&emsp; &emsp; 时间复杂度 O(n)，空间复杂度 O(1)。

## 054 . 螺旋矩阵

&emsp; &emsp; 通过观察可知前 row / 2 + row % 2 的行为顺序遍历，后 row / 2 的行为反向遍历，右 col / 2 + col % 2 列的为顺序遍历，左 col / 2 的列为反向遍历。同时约定每一圈的顺序遍历的个数比反向遍历的个数多一个，然后当行遍历完判断是否为 row / 2 行，从上往下遍历列时判断是否为 col / 2 列，从下往上遍历列时，判断是否 col / 2 - 1 列，是则结束遍历。<br/>
&emsp; &emsp; 时间复杂度 O(n)，空间复杂度 O(1)。

## 055. 跳跃游戏

&emsp; &emsp; 经典贪心题目，参照 45 题做法。只需遍历 size - 2 项，当 i 等于上次的最远位置且最远位置没有被更新时，返回 false，否则返回 true。<br/>
&emsp; &emsp; 时间复杂度 O(n)，空间复杂度 O(1)。

## 056 . 合并区间

&emsp; &emsp; 先对区间以每个区间的首元素进行排序，然后遍历区间，将第一个区间插入结果，当后一个区间的首元素比结果的最后一个区间的首元素大时，更新最后一个区间的右区间，直到遍历完结果。<br/>
&emsp; &emsp; 时间复杂度遍历依次数组以及做一次排序的耗时 O(n) + O(nlogn) = O(nlogn)，空间复杂度 O(1)。

## 057 . 插入区间

&emsp; &emsp; 56 题变种，由于题目保证了原区间有序且不重叠，只需要在原区间中二分查找找到插入位置，然后在原数组以插入位置为起始点分别向后遍历看是否需要合并区间，最后不需要合并区间的地方依次加入结果数组即可。<br/>
&emsp; &emsp; 时间复杂度 O(logn) + O(n) = O(n)，空间复杂度 O(1)。

## 058 . 最后一个单词的长度

&emsp; &emsp; 送分题。<br/>
&emsp; &emsp; 时间复杂度 O(n)，空间复杂度 O(1)。

## 059 . 螺旋矩阵 II

&emsp; &emsp; 54 题变种，初始化数组然后根据 54 的遍历方式给数组赋值即可。<br/>
&emsp; &emsp; 同时由于是 n * n 的矩阵且最后的值为 n ^ 2，因此只需要在横向的时候判断当前已赋过的值是否等于 n ^ 2 即可退出循环。<br/>
&emsp; &emsp; 时间复杂度 O(n ^ 2)，空间复杂度 O(1)。

## 060 . 排列序列

&emsp; &emsp; 方法 1 ： 不带脑子，46 题的变种，通过一个全局变量记录当前为第几个，以及利用一个标志位判断之前的递归是否已得到结果，已得到则不再遍历即可。<br/>
&emsp; &emsp; 时间复杂度 O(m)，空间复杂度为存放各个位使用情况的状态数组以及存放当前结果的结果数组总的数组空间 O(n) 以及递归深度 O(n) = O(n)。<br/>
&emsp; &emsp; 方法 2 ： 带脑子，根据数学性质，分别将 k 对 (n - 1)!、(n - 2)!、(n - 3)!... 1 进行相除，获得商作为当前数组的下标，然后余数用于下一轮相除，得到最后即为结果。 <br/>
&emsp; &emsp; 时间复杂度 O(n)，空间复杂度为存放集合数组的长度 O(n)。<br/>

## 061 . 旋转链表

&emsp; &emsp; 先遍历一次链表，得到链表长度。如果链表长度小于等于 1 则直接返回 head，然后将 k 对链表长度进行取余，如果 k 的值等于 0 则直接返回 head。然后遍历链表获得链表的倒数第 k 个节点以及倒数第 k + 1 个节点，倒数第 k + 1 个节点 next 置为 nullptr，倒数第 k 个节点 next 置为原本的 head 即可。<br/>
&emsp; &emsp; 时间复杂度 O(n)，空间复杂度 O(1)。

## 062 . 不同路径

&emsp; &emsp; 方法 1 ： 不带脑子，经典 dp，创建 m * n 长度的 dp 数组，每个元素为其左边元素以及右边元素的和。最后 dp[m - 1][n - 1] 即为所得结果。<br/>
&emsp; &emsp; 时间复杂度 O(m * n)，空间复杂度 O(m * n)。<br/>
&emsp; &emsp; 方法 2 ： 带脑子，相当于在 m + n -2 中选取 m - 1 个地方插入下符号或者选取 n - 1 个地方插入右符号，根据排列组合性质可知，这两者结果一致，所以可选取更小的一方以减少阶乘所耗的时间。<br/>
&emsp; &emsp; 时间复杂度 O(min(m, n))，空间复杂度 O(1)。

## 063 . 不同路径 II

&emsp; &emsp; 方法 1 ： 不带脑子，经典 dp，创建 m * n 长度的 dp 数组，每个元素为其左边元素以及右边元素的和。最后 dp[m - 1][n - 1] 即为所得结果。<br/>
&emsp; &emsp; 时间复杂度 O(m * n)，使用长度为 n 的滚动数组，在下一次遍历时重新给数组赋值，可以将空间复杂度优化为 O(n)。

## 064 . 最小路径和

&emsp; &emsp; 经典 dp。先遍历第一行给 dp 数组赋初始值。后续行遍历时，dp 的值为先前的值以及上一次轮遍历时的值和前一个元素的最小值。<br/>
&emsp; &emsp; 时间复杂度 O(m * n)，使用滚动数组将空间复杂度优化到 O(n)。

## 065 . 有效数字

&emsp; &emsp; 首先先判断第一位是否正负号，是则开始遍历的下标从 1 开始，然后开始遍历。<br/>
&emsp; &emsp; 通过状态位标志是否遍历过数字、是否遍历过小数点，当遍历到小数点时，若先前遍历过小数点，则返回 false。<br/>
&emsp; &emsp; 遍历到 e 时，若之前没有遍历过数字，则返回 false。否则则判断后续是否一个整数，如果后续长度为 0 则返回 false，否则进行整数判断。<br/>
&emsp; &emsp; 如果没有遍历到 e，最后则会返回是否遍历过数字即可。
&emsp; &emsp; 时间复杂度 O(n)，空间复杂度 O(1)。

## 066 . 加一

&emsp; &emsp; 通过标志位判断是否需要对当前位进 1。同时遍历完数组后，如果标志位仍为 true，则需要在 0 插入 1。<br/>
&emsp; &emsp; 时间复杂度 O(n)，空间复杂度 O(1)。

## 067 . 二进制求和

&emsp; &emsp; 通过标志位判断是否需要对当前位进 1。同时遍历完数组后，如果标志位仍为 true，则需要在 0 插入 1。<br/>
&emsp; &emsp; 在具体实现上，使用临时变量存储长度较短的字符串以及长度较长的字符串，使用反向迭代器，遍历完较短数组后再去遍历较长数组即可。<br/>
&emsp; &emsp; 时间复杂度 O(n)，空间复杂度 O(1)。

## 068 . 文本左右对齐

&emsp; &emsp; 写作贪心，实际上为各种丑陋的边界条件处理（bushi）。需要特别注意不是最后一行时，不能刚好用单词填满空位，需要留有空格。总感觉题目哪里有些问题。<br/>
&emsp; &emsp; 时间复杂度 O(n)，空间复杂度 O(1)。

## 068 . 文本左右对齐

&emsp; &emsp; 写作贪心，实际上为各种丑陋的特殊处理（bushi）。需要特别注意不是最后一行时，不能刚好用单词填满空位，需要留有空格。总感觉题目哪里有些问题。<br/>
&emsp; &emsp; 时间复杂度 O(n)，空间复杂度 O(1)。

## 069. Sqrt(x)

&emsp; &emsp; 方法 1：通过牛顿迭代法找到最终结果。<br/>
&emsp; &emsp; 迭代结果按对数级收敛，时间复杂度 O(logn)，空间复杂度 O(1)。<br/>
&emsp; &emsp; 方法 2：官方做法，不允许直接使用指数函数，但将原函数转为关于 e 的幂函数以及对数函数达成目标。 x ^ (1/2) = (e ^ (lnx)) ^ (1 / 2) = e ^ ((1 / 2) * lnx)。同时考虑到浮点数运算的误差，需要判断该结果 +1 时的平方是否小于结果，是则返回 +1 的结果。<br/>
&emsp; &emsp; 时间复杂度 O(1)，空间复杂度 O(1)。

## 070. 爬楼梯

&emsp; &emsp; 经典 dp，使用滚动数组减少空间复杂度。<br/>
&emsp; &emsp; 时间复杂度 O(n)，空间复杂度 O(1)。

## 637 . 二叉树的层平均值

&emsp; &emsp; 广度优先搜索。<br/>
&emsp; &emsp; 时间复杂度 O(n)，空间复杂度 O(n)。

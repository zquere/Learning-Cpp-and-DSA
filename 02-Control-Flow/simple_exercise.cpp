#include <iostream>
#include <string>
using namespace std;


// ============================================================
//              CONTROL FLOW | PROBLEM SOLVING
// ============================================================
// Think about:
//
//     Logic
//     Edge cases
//     Time complexity
//     Space complexity
//     Optimization
//
// ============================================================


// ============================================================
// Q01 | Reverse a word
// ============================================================
//
// Problem:
//
// You are given a word:
//
//     "lemon"
//
// Reverse the word.
//
// Expected:
//
//     "nomel"
//
// Example:
//
//     Input:  lemon
//     Output: nomel
//
// ------------------------------------------------------------
//
// YOUR CODE:
//
// Try it yourself first.
//
// ------------------------------------------------------------
//
// ANSWER:
//
// string word = "lemon";
//
// for (int i = word.length() - 1; i >= 0; i--) {
//     cout << word[i];
// }
//
// ------------------------------------------------------------
//
// EXPLANATION:
//
// "lemon" has indexes:
//
//     l e m o n
//     0 1 2 3 4
//
// We start from the last index:
//
//     4 -> n
//     3 -> o
//     2 -> m
//     1 -> e
//     0 -> l
//
// Therefore:
//
//     nomel
//
// ------------------------------------------------------------
//
// TIME:
//
//     O(n)
//
// We visit every character once.
//
// SPACE:
//
//     O(1)
//
// We don't create another string.
//
// ------------------------------------------------------------
//
// OPTIMIZATION:
//
// This is already optimal in terms of time.
//
// You cannot reverse n characters without looking at
// the characters, so O(n) is necessary.
//
// ============================================================


// ============================================================
// Q02 | Count vowels
// ============================================================
//
// Problem:
//
// Given a string:
//
//     "programming"
//
// Count how many vowels it contains.
//
// Vowels:
//
//     a e i o u
//
// Expected:
//
//     3
//
// ------------------------------------------------------------
//
// ANSWER:
//
// string word = "programming";
// int count = 0;
//
// for (int i = 0; i < word.length(); i++) {
//
//     if (word[i] == 'a' ||
//         word[i] == 'e' ||
//         word[i] == 'i' ||
//         word[i] == 'o' ||
//         word[i] == 'u') {
//
//         count++;
//     }
// }
//
// cout << count;
//
// ------------------------------------------------------------
//
// EXPLANATION:
//
// We examine every character.
//
// programming
//      ↓
// o -> vowel
// a -> vowel
// i -> vowel
//
// Total:
//
//     3
//
// ------------------------------------------------------------
//
// TIME:
//
//     O(n)
//
// Every character may need to be checked.
//
// SPACE:
//
//     O(1)
//
// Only count is stored.
//
// ------------------------------------------------------------
//
// OPTIMIZATION:
//
// There isn't a meaningful Big-O improvement.
//
// O(n) is necessary because the vowel could be at the
// very last character.
//
// ============================================================


// ============================================================
// Q03 | Count digits in a number
// ============================================================
//
// Problem:
//
// Given:
//
//     n = 58392
//
// Find how many digits it contains.
//
// Expected:
//
//     5
//
// ------------------------------------------------------------
//
// ANSWER:
//
// int n = 58392;
// int count = 0;
//
// while (n > 0) {
//
//     n = n / 10;
//     count++;
// }
//
// cout << count;
//
// ------------------------------------------------------------
//
// EXPLANATION:
//
// Every integer division by 10 removes the last digit.
//
//     58392 -> 5839
//     5839  -> 583
//     583   -> 58
//     58    -> 5
//     5     -> 0
//
// We removed 5 digits.
//
// Therefore:
//
//     count = 5
//
// ------------------------------------------------------------
//
// TIME:
//
//     O(log n)
//
// This is NOT O(n).
//
// The number becomes roughly 10 times smaller
// after every iteration.
//
// ------------------------------------------------------------
//
// IMPORTANT:
//
// Understanding this difference becomes very useful later
// when studying DSA.
//
// ============================================================


// ============================================================
// Q04 | Reverse a number
// ============================================================
//
// Problem:
//
// Given:
//
//     n = 12345
//
// Reverse the number.
//
// Expected:
//
//     54321
//
// ------------------------------------------------------------
//
// ANSWER:
//
// int n = 12345;
// int reversed = 0;
//
// while (n > 0) {
//
//     int digit = n % 10;
//
//     reversed = reversed * 10 + digit;
//
//     n = n / 10;
// }
//
// cout << reversed;
//
// ------------------------------------------------------------
//
// EXPLANATION:
//
// First:
//
//     12345 % 10 = 5
//
// reversed:
//
//     0 * 10 + 5 = 5
//
// Next:
//
//     1234 % 10 = 4
//
//     5 * 10 + 4 = 54
//
// Next:
//
//     123 % 10 = 3
//
//     54 * 10 + 3 = 543
//
// Continue:
//
//     5432
//     54321
//
// Final answer:
//
//     54321
//
// ------------------------------------------------------------
//
// TIME:
//
//     O(log n)
//
// We process each digit once.
//
// SPACE:
//
//     O(1)
//
// ------------------------------------------------------------
//
// OPTIMIZATION:
//
// The important optimization is NOT making the loop shorter.
//
// It is using:
//
//     % 10
//
// to extract the digit directly.
//
// No string conversion is required.
//
// ============================================================


// ============================================================
// Q05 | Check palindrome number
// ============================================================
//
// Problem:
//
// A palindrome reads the same forward and backward.
//
// Example:
//
//     121 -> palindrome
//     123 -> not palindrome
//
// Determine whether:
//
//     1221
//
// is a palindrome.
//
// ------------------------------------------------------------
//
// ANSWER:
//
// int n = 1221;
// int original = n;
// int reversed = 0;
//
// while (n > 0) {
//
//     int digit = n % 10;
//     reversed = reversed * 10 + digit;
//     n /= 10;
// }
//
// if (original == reversed) {
//     cout << "Palindrome";
// }
// else {
//     cout << "Not Palindrome";
// }
//
// ------------------------------------------------------------
//
// EXPLANATION:
//
// Original:
//
//     1221
//
// Reverse:
//
//     1221
//
// Compare:
//
//     1221 == 1221
//
// Therefore:
//
//     Palindrome
//
// ------------------------------------------------------------
//
// TIME:
//
//     O(log n)
//
// SPACE:
//
//     O(1)
//
// ------------------------------------------------------------
//
// OPTIMIZATION:
//
// We don't need to convert the number to a string.
//
// The mathematical approach uses constant extra space.
//
// ============================================================


// ============================================================
// Q06 | Find the largest digit
// ============================================================
//
// Problem:
//
// Given:
//
//     583921
//
// Find the largest digit.
//
// Expected:
//
//     9
//
// ------------------------------------------------------------
//
// ANSWER:
//
// int n = 583921;
// int largest = 0;
//
// while (n > 0) {
//
//     int digit = n % 10;
//
//     if (digit > largest) {
//         largest = digit;
//     }
//
//     n /= 10;
// }
//
// cout << largest;
//
// ------------------------------------------------------------
//
// EXPLANATION:
//
// Check each digit:
//
//     1 -> largest = 1
//     2 -> largest = 2
//     9 -> largest = 9
//     3 -> stays 9
//     8 -> stays 9
//     5 -> stays 9
//
// Final:
//
//     9
//
// ------------------------------------------------------------
//
// TIME:
//
//     O(log n)
//
// SPACE:
//
//     O(1)
//
// ------------------------------------------------------------


// ============================================================
// Q07 | Count even and odd digits
// ============================================================
//
// Problem:
//
// Given:
//
//     583921
//
// Count:
//
//     even digits
//     odd digits
//
// Expected:
//
//     Even = 2
//     Odd  = 4
//
// ------------------------------------------------------------
//
// ANSWER:
//
// int n = 583921;
// int even = 0;
// int odd = 0;
//
// while (n > 0) {
//
//     int digit = n % 10;
//
//     if (digit % 2 == 0) {
//         even++;
//     }
//     else {
//         odd++;
//     }
//
//     n /= 10;
// }
//
// cout << "Even: " << even << endl;
// cout << "Odd: " << odd << endl;
//
// ------------------------------------------------------------
//
// LOGIC:
//
// First % 10 gets the digit.
//
// Second % 2 checks whether that digit is even.
//
// This is a good example of combining two ideas:
//
//     digit extraction
//            +
//     conditional logic
//
// ============================================================


// ============================================================
// Q08 | Find the first repeated character
// ============================================================
//
// Problem:
//
// Given:
//
//     "programming"
//
// Find the first character that appears more than once.
//
// Expected:
//
//     r
//
// ------------------------------------------------------------
//
// Think before coding.
//
// You need to compare characters.
//
// ------------------------------------------------------------
//
// SIMPLE ANSWER:
//
// string s = "programming";
//
// for (int i = 0; i < s.length(); i++) {
//
//     for (int j = i + 1; j < s.length(); j++) {
//
//         if (s[i] == s[j]) {
//             cout << s[i];
//             return 0;
//         }
//     }
// }
//
// ------------------------------------------------------------
//
// EXPLANATION:
//
// For every character:
//
//     compare it with characters after it.
//
// This finds the first repeated character.
//
// ------------------------------------------------------------
//
// TIME:
//
//     O(n²)
//
// because of the nested loops.
//
// SPACE:
//
//     O(1)
//
// ------------------------------------------------------------
//
// CAN WE OPTIMIZE?
//
// Yes.
//
// Later, when you learn arrays / frequency counting,
// we can store whether a character has already appeared.
//
// Then:
//
//     O(n²) -> O(n)
//
// This is an important DSA pattern:
//
//     More memory
//          ↓
//     Less computation
//
// ============================================================


// ============================================================
// Q09 | Find whether a number is prime
// ============================================================
//
// Problem:
//
// Given:
//
//     n = 97
//
// Determine whether it is prime.
//
// ------------------------------------------------------------
//
// SIMPLE ANSWER:
//
// int n = 97;
// bool prime = true;
//
// if (n < 2) {
//     prime = false;
// }
//
// for (int i = 2; i < n; i++) {
//
//     if (n % i == 0) {
//         prime = false;
//         break;
//     }
// }
//
// if (prime) {
//     cout << "Prime";
// }
// else {
//     cout << "Not Prime";
// }
//
// ------------------------------------------------------------
//
// BUT THIS IS NOT THE BEST VERSION.
//
// We don't need to check every number until n.
//
// If n has a factor larger than sqrt(n),
// it must have another factor smaller than sqrt(n).
//
// So we only need:
//
//     i * i <= n
//
// ------------------------------------------------------------
//
// OPTIMIZED:
//
// int n = 97;
// bool prime = true;
//
// if (n < 2) {
//     prime = false;
// }
//
// for (int i = 2; i * i <= n; i++) {
//
//     if (n % i == 0) {
//         prime = false;
//         break;
//     }
// }
//
// cout << (prime ? "Prime" : "Not Prime");
//
// ------------------------------------------------------------
//
// COMPLEXITY:
//
// Before:
//
//     O(n)
//
// After:
//
//     O(sqrt(n))
//
// This is a real algorithmic optimization.
//
// ============================================================


// ============================================================
// Q10 | Find the missing number
// ============================================================
//
// Problem:
//
// You are given numbers from 1 to n,
// but exactly one number is missing.
//
// Example:
//
//     1 2 3 5
//
// n = 5
//
// Missing number:
//
//     4
//
// ------------------------------------------------------------
//
// SIMPLE CONTROL-FLOW APPROACH:
//
// int n = 5;
// int sum = 0;
//
// for (int i = 1; i <= n; i++) {
//     sum += i;
// }
//
// int given[] = {1, 2, 3, 5};
//
// for (int i = 0; i < n - 1; i++) {
//     sum -= given[i];
// }
//
// cout << sum;
//
// ------------------------------------------------------------
//
// EXPLANATION:
//
// Expected sum:
//
//     1 + 2 + 3 + 4 + 5 = 15
//
// Given:
//
//     1 + 2 + 3 + 5 = 11
//
// Difference:
//
//     15 - 11 = 4
//
// ------------------------------------------------------------
//
// OPTIMIZATION:
//
// We can calculate:
//
//     1 + 2 + ... + n
//
// using:
//
//     n * (n + 1) / 2
//
// So we don't need the first loop.
//
// Expected:
//
//     long long expected = 1LL * n * (n + 1) / 2;
//
// Then subtract the given numbers.
//
// This reduces unnecessary work.
//
// ------------------------------------------------------------
//
// TIME:
//
//     O(n)
//
// because we still need to inspect the given numbers.
//
// SPACE:
//
//     O(1)
//
// ============================================================


// ============================================================
// Q11 | HARDER | Move all zeros to the end
// ============================================================
//
// Problem:
//
// Given:
//
//     1 0 3 0 5 0 2
//
// Move all zeros to the end.
//
// Expected:
//
//     1 3 5 2 0 0 0
//
// The order of non-zero numbers must remain the same.
//
// ------------------------------------------------------------
//
// SOLUTION:
//
// int arr[] = {1, 0, 3, 0, 5, 0, 2};
// int n = 7;
//
// int position = 0;
//
// for (int i = 0; i < n; i++) {
//
//     if (arr[i] != 0) {
//
//         arr[position] = arr[i];
//         position++;
//     }
// }
//
// while (position < n) {
//
//     arr[position] = 0;
//     position++;
// }
//
// ------------------------------------------------------------
//
// IDEA:
//
// position tells us where the next non-zero number belongs.
//
// We scan the array once.
//
// ------------------------------------------------------------
//
// TIME:
//
//     O(n)
//
// SPACE:
//
//     O(1)
//
// ------------------------------------------------------------
//
// This is much better than repeatedly shifting elements,
// which can accidentally turn the solution into O(n²).
//
// ============================================================


// ============================================================
// Q12 | HARD | Longest consecutive sequence
// ============================================================
//
// Problem:
//
// Given:
//
//     1 2 3 7 8 9 10 2
//
// Find the length of the longest consecutive run.
//
// Answer:
//
//     4
//
// Because:
//
//     7 8 9 10
//
// ------------------------------------------------------------
//
// CODE:
//
// int arr[] = {1, 2, 3, 7, 8, 9, 10, 2};
// int n = 8;
//
// int current = 1;
// int longest = 1;
//
// for (int i = 1; i < n; i++) {
//
//     if (arr[i] == arr[i - 1] + 1) {
//
//         current++;
//
//     }
//     else {
//
//         current = 1;
//     }
//
//     if (current > longest) {
//         longest = current;
//     }
// }
//
// cout << longest;
//
// ------------------------------------------------------------
//
// WHY IT WORKS:
//
// Compare the current number with the previous number.
//
// If:
//
//     current == previous + 1
//
// then the sequence continues.
//
// Otherwise:
//
//     start a new sequence.
//
// ------------------------------------------------------------
//
// TIME:
//
//     O(n)
//
// SPACE:
//
//     O(1)
//
// ------------------------------------------------------------
//
// This is the kind of problem where control flow starts
// becoming actual DSA thinking.
//
// ============================================================


// ============================================================
// Q13 | HARD | Maximum subarray sum
// ============================================================
//
// Problem:
//
// Given:
//
//     -2 1 -3 4 -1 2 1 -5 4
//
// Find the largest possible sum of a continuous subarray.
//
// Answer:
//
//     6
//
// Because:
//
//     4 + (-1) + 2 + 1 = 6
//
// ------------------------------------------------------------
//
// NAIVE:
//
// Try every possible subarray.
//
// That leads to O(n²) or O(n³) depending on implementation.
//
// ------------------------------------------------------------
//
// BETTER IDEA:
//
// Keep a running sum.
//
// If the current sum becomes worse than starting fresh,
// start again.
//
// ------------------------------------------------------------
//
// int current = 0;
// int best = arr[0];
//
// for (int i = 0; i < n; i++) {
//
//     current += arr[i];
//
//     if (current > best) {
//         best = current;
//     }
//
//     if (current < 0) {
//         current = 0;
//     }
// }
//
// cout << best;
//
// ------------------------------------------------------------
//
// TIME:
//
//     O(n)
//
// SPACE:
//
//     O(1)
//
// ------------------------------------------------------------
//
// This is Kadane's algorithm.
//
// The important lesson is not memorizing the name.
//
// It is recognizing:
//
//     "I don't need to remember every possible subarray."
//
// I only need the useful state from the previous step.
//
// ============================================================


// ============================================================
//                 OPTIMIZATION MINDSET
// ============================================================
//
// When solving a problem, don't immediately ask:
//
//     "How do I write the loop?"
//
// Ask:
//
//     1. What information do I actually need?
//
//     2. Do I need to check every element?
//
//     3. Can I stop early?
//
//     4. Can I calculate the answer directly?
//
//     5. Am I repeating the same work?
//
//     6. Can I store information so I don't calculate it again?
//
//     7. Can nested loops be removed?
//
//     8. What is my time complexity?
//
//     9. What is my space complexity?
//
//     10. Is the optimization worth the extra memory/code?
//
// ============================================================

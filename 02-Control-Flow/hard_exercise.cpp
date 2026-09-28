#include <iostream>
#include <vector>
#include <string>
using namespace std;


// ============================================================
//              CONTROL FLOW → LOGIC TRAINING [HARDER]
// ============================================================
//
// These are NOT syntax exercises.
//
// The goal is to learn how to:
//
//     -> break a problem into states
//     -> choose what information to remember
//     -> control a loop correctly
//     -> recognize unnecessary work
//     -> improve an O(n²) idea
//     -> reason about edge cases
//
// Try every problem before reading the solution.
//
// ============================================================


// ============================================================
// Q01 | The Last Safe Position
// ============================================================
//
// You are walking through a row of positions.
//
// Each position contains either:
//
//     0 -> safe
//     1 -> dangerous
//
// Example:
//
//     0 0 1 0 0 1 0
//
// Find the number of consecutive safe positions at the end.
//
// Answer:
//
//     1
//
// Because the array ends with:
//
//     ... 1 0
//
// ------------------------------------------------------------
//
// THINK:
//
// Do you actually need to inspect the entire array?
//
// ------------------------------------------------------------
//
// SOLUTION:
//
// vector<int> a = {0, 0, 1, 0, 0, 1, 0};
//
// int count = 0;
//
// for (int i = a.size() - 1; i >= 0; i--) {
//
//     if (a[i] == 0) {
//         count++;
//     }
//     else {
//         break;
//     }
// }
//
// cout << count;
//
// ------------------------------------------------------------
//
// WHY?
//
// We only care about the END.
//
// Starting from the end lets us stop immediately
// when we find the first dangerous position.
//
// ------------------------------------------------------------
//
// OPTIMIZATION:
//
// A left-to-right solution would inspect everything.
//
// This solution can stop early.
//
// Best case:
//
//     O(1)
//
// Worst case:
//
//     O(n)
//
// This is an early-termination pattern.
//
// ============================================================


// ============================================================
// Q02 | When Does the System Become Unstable?
// ============================================================
//
// A system receives values one by one.
//
// Start with:
//
//     balance = 0
//
// For every value:
//
//     positive -> add it
//     negative -> subtract its absolute value
//
// The system becomes unstable if balance ever becomes negative.
//
// Given:
//
//     4 3 -2 -10 7
//
// Determine whether the system becomes unstable.
//
// ------------------------------------------------------------
//
// SOLUTION:
//
// vector<int> a = {4, 3, -2, -10, 7};
//
// int balance = 0;
// bool unstable = false;
//
// for (int x : a) {
//
//     balance += x;
//
//     if (balance < 0) {
//         unstable = true;
//         break;
//     }
// }
//
// cout << (unstable ? "Unstable" : "Stable");
//
// ------------------------------------------------------------
//
// IMPORTANT IDEA:
//
// We don't need the final balance.
//
// We care about whether the condition was EVER true.
//
// This creates a useful pattern:
//
//     "Did something happen at any point?"
//
// ------------------------------------------------------------
//
// DSA CONNECTION:
//
// This idea appears everywhere:
//
//     prefix conditions
//     running state
//     validation
//     simulation
//     greedy algorithms
//
// Time:
//
//     O(n)
//
// Space:
//
//     O(1)
//
//
// ============================================================


// ============================================================
// Q03 | The Longest Streak
// ============================================================
//
// A game records:
//
//     W -> win
//     L -> loss
//
// Given:
//
//     W W L W W W L W
//
// Find the longest consecutive winning streak.
//
// Expected:
//
//     3
//
// ------------------------------------------------------------
//
// Don't count every possible sequence.
//
// Maintain only two pieces of information:
//
//     current streak
//     best streak
//
// ------------------------------------------------------------
//
// SOLUTION:
//
// string games = "WWLWWWLW";
//
// int current = 0;
// int best = 0;
//
// for (char result : games) {
//
//     if (result == 'W') {
//
//         current++;
//
//         if (current > best) {
//             best = current;
//         }
//
//     }
//     else {
//
//         current = 0;
//     }
// }
//
// cout << best;
//
// ------------------------------------------------------------
//
// KEY IDEA:
//
// When L appears:
//
//     current = 0
//
// We throw away the old streak because it cannot continue.
//
// This is called maintaining STATE.
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
// DSA CONNECTION:
//
// This same idea appears in:
//
//     maximum subarray
//     longest valid sequence
//     sliding window
//     dynamic programming
//
// ============================================================


// ============================================================
// Q04 | Can We Reach the End?
// ============================================================
//
// You are given jumps:
//
//     2 3 1 1 4
//
// Each number tells you the maximum number of positions
// you can move forward from that position.
//
// Starting at index 0, determine whether you can reach
// the final index.
//
// ------------------------------------------------------------
//
// Example:
//
// index:  0 1 2 3 4
// value:  2 3 1 1 4
//
// From index 0:
//
//     maximum reach = 2
//
// From index 1:
//
//     maximum reach = 4
//
// So the end is reachable.
//
// ------------------------------------------------------------
//
// SOLUTION:
//
// vector<int> jumps = {2, 3, 1, 1, 4};
//
// int farthest = 0;
//
// for (int i = 0; i < jumps.size(); i++) {
//
//     if (i > farthest) {
//         break;
//     }
//
//     farthest = max(farthest, i + jumps[i]);
//
//     if (farthest >= jumps.size() - 1) {
//         cout << "YES";
//         return 0;
//     }
// }
//
// cout << "NO";
//
// ------------------------------------------------------------
//
// IMPORTANT:
//
// We don't try every possible jump.
//
// We only remember:
//
//     farthest position reachable so far.
//
// This is a major algorithmic idea:
//
//     compress many possibilities into one useful state.
//
// ------------------------------------------------------------
//
// COMPLEXITY:
//
//     O(n)
//
// instead of exploring every possible sequence of jumps.
//
// ------------------------------------------------------------
//
// DSA CONNECTION:
//
// This introduces the thinking behind GREEDY algorithms.
//
// ============================================================


// ============================================================
// Q05 | Find the First Point Where Two Processes Meet
// ============================================================
//
// Two runners move through the same timeline.
//
// Runner A visits:
//
//     1 3 5 7 9
//
// Runner B visits:
//
//     2 4 6 7 8
//
// Find the first position they both visit.
//
// Expected:
//
//     7
//
// ------------------------------------------------------------
//
// A naive solution:
//
//     compare every A with every B
//
// That gives:
//
//     O(n²)
//
// But notice:
//
// Both sequences are ordered.
//
// Can we use that?
//
// ------------------------------------------------------------
//
// SOLUTION:
//
// vector<int> A = {1, 3, 5, 7, 9};
// vector<int> B = {2, 4, 6, 7, 8};
//
// int i = 0;
// int j = 0;
//
// while (i < A.size() && j < B.size()) {
//
//     if (A[i] == B[j]) {
//         cout << A[i];
//         break;
//     }
//
//     if (A[i] < B[j]) {
//         i++;
//     }
//     else {
//         j++;
//     }
// }
//
// ------------------------------------------------------------
//
// WHY DOES THIS WORK?
//
// If:
//
//     A[i] < B[j]
//
// then A[i] cannot match B[j]
// or anything before B[j].
//
// So we safely discard A[i].
//
// This is the beginning of the TWO POINTER technique.
//
// ------------------------------------------------------------
//
// Naive:
//
//     O(n²)
//
// Optimized:
//
//     O(n)
//
// This is exactly the kind of optimization you want
// before entering DSA.
//
// ============================================================


// ============================================================
// Q06 | Minimum Number of Platforms
// ============================================================
//
// Trains arrive and leave.
//
// Arrival:
//
//     1 2 3 4
//
// Departure:
//
//     2 3 4 5
//
// Find the maximum number of trains at the station
// at the same time.
//
// ------------------------------------------------------------
//
// This problem looks complicated.
//
// But break it into events.
//
// Arrival -> +1
// Departure -> -1
//
// Sort the events and maintain:
//
//     current trains
//     maximum trains
//
// ------------------------------------------------------------
//
// SOLUTION IDEA:
//
// int current = 0;
// int maximum = 0;
//
// for each event:
//
//     arrival:
//         current++;
//
//     departure:
//         current--;
//
//     maximum = max(maximum, current);
//
// ------------------------------------------------------------
//
// The important lesson:
//
// A complicated real-world problem can often become
// a simple state simulation.
//
// ------------------------------------------------------------
//
// DSA CONNECTION:
//
// This leads toward:
//
//     sorting
//     event processing
//     greedy algorithms
//     sweep line
//
// ============================================================


// ============================================================
// Q07 | Remove Repeated Work
// ============================================================
//
// Given:
//
//     1 2 3 4 5 6 7 8 9 10
//
// For every number, determine whether another number
// in the array adds up to 10.
//
// ------------------------------------------------------------
//
// BAD IDEA:
//
// for every i
//     for every j
//
// Time:
//
//     O(n²)
//
// ------------------------------------------------------------
//
// BETTER THINKING:
//
// If:
//
//     x + y = 10
//
// then:
//
//     y = 10 - x
//
// So instead of searching for y repeatedly,
// remember what numbers have already appeared.
//
// ------------------------------------------------------------
//
// This leads to the idea of:
//
//     hashing / lookup
//
// which later becomes a major DSA technique.
//
// ------------------------------------------------------------
//
// IMPORTANT:
//
// The optimization isn't about changing:
//
//     for
//
// into:
//
//     while
//
// The optimization is about changing the algorithm.
//
// ============================================================


// ============================================================
// Q08 | The Majority
// ============================================================
//
// You are given:
//
//     2 2 1 1 1 2 2
//
// Find the value that appears more than n/2 times.
//
// Expected:
//
//     2
//
// ------------------------------------------------------------
//
// First instinct:
//
// Count every value.
//
// That works, but requires extra memory.
//
// Can we do it with only a few variables?
//
// ------------------------------------------------------------
//
// SOLUTION:
//
// int candidate = 0;
// int count = 0;
//
// for (int x : a) {
//
//     if (count == 0) {
//         candidate = x;
//     }
//
//     if (x == candidate) {
//         count++;
//     }
//     else {
//         count--;
//     }
// }
//
// cout << candidate;
//
// ------------------------------------------------------------
//
// This is the idea behind Boyer-Moore voting.
//
// The important lesson:
//
// Different values can cancel each other.
//
// Instead of remembering everything,
// we keep only the information necessary
// to determine the surviving candidate.
//
// ------------------------------------------------------------
//
// Time:
//
//     O(n)
//
// Space:
//
//     O(1)
//
// ------------------------------------------------------------
//
// This is much closer to actual DSA reasoning.
//
// ============================================================


// ============================================================
// Q09 | HARD | Is the sequence valid?
// ============================================================
//
// A string contains:
//
//     '(' and ')'
//
// Determine whether the brackets are correctly balanced.
//
// Examples:
//
//     "(())" -> valid
//     "(()"  -> invalid
//     ")("   -> invalid
//     "()()" -> valid
//
// ------------------------------------------------------------
//
// THINK:
//
// What state do we need to remember?
//
// Answer:
//
//     balance
//
// '(' -> +1
// ')' -> -1
//
// At ANY point:
//
//     balance < 0
//
// means a closing bracket appeared before
// its matching opening bracket.
//
// At the end:
//
//     balance must equal 0.
//
// ------------------------------------------------------------
//
// SOLUTION:
//
// int balance = 0;
//
// for (char c : s) {
//
//     if (c == '(') {
//         balance++;
//     }
//     else {
//         balance--;
//
//         if (balance < 0) {
//             cout << "Invalid";
//             return 0;
//         }
//     }
// }
//
// if (balance == 0) {
//     cout << "Valid";
// }
// else {
//     cout << "Invalid";
// }
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
// IMPORTANT:
//
// This is a classic example of a LOOP INVARIANT:
//
//     balance = opening brackets that
//               haven't been matched yet.
//
// That concept becomes extremely important in DSA.
//
// ============================================================


// ============================================================
// Q10 | HARD | Find the first place the array becomes invalid
// ============================================================
//
// A sequence is supposed to be strictly increasing.
//
// Example:
//
//     2 4 7 9 12
//
// is valid.
//
// But:
//
//     2 4 7 6 12
//
// becomes invalid at index 3.
//
// Find the first invalid index.
//
// ------------------------------------------------------------
//
// SOLUTION:
//
// for (int i = 1; i < n; i++) {
//
//     if (a[i] <= a[i - 1]) {
//
//         cout << i;
//         break;
//     }
// }
//
// ------------------------------------------------------------
//
// WHY START AT 1?
//
// Because we compare:
//
//     a[i]
//     with
//     a[i - 1]
//
// There is no previous element for index 0.
//
// ------------------------------------------------------------
//
// TIME:
//
//     O(n)
//
// But in the best case:
//
//     O(1)
//
// if the second element already breaks the rule.
//
// ------------------------------------------------------------
//
// This is an example of:
//
//     local comparison
//
// We don't need the entire history.
// Only the previous element matters.
//
// ============================================================


// ============================================================
// Q11 | HARD | Can we make all values equal?
// ============================================================
//
// Given:
//
//     2 2 3 2 2
//
// You are allowed to remove elements.
//
// Can you make all remaining elements equal?
//
// ------------------------------------------------------------
//
// THINK:
//
// Instead of asking:
//
//     "How do I remove elements?"
//
// ask:
//
//     "Which value should I KEEP?"
//
// The best candidate is the value appearing most often.
//
// Therefore:
//
//     elements to remove
//         =
//     n - frequency of most common value
//
// ------------------------------------------------------------
//
// This is an important DSA transformation:
//
// Change the question.
//
// Instead of optimizing what to remove,
// optimize what to keep.
//
// ============================================================


// ============================================================
// Q12 | VERY HARD | Sliding Window Thinking
// ============================================================
//
// Given:
//
//     2 1 5 1 3 2
//
// Find the maximum sum of any 3 consecutive elements.
//
// Example windows:
//
//     2 1 5 -> 8
//     1 5 1 -> 7
//     5 1 3 -> 9
//     1 3 2 -> 6
//
// Answer:
//
//     9
//
// ------------------------------------------------------------
//
// BAD APPROACH:
//
// Recalculate every window from scratch.
//
// That repeats work.
//
// ------------------------------------------------------------
//
// SMART APPROACH:
//
// First window:
//
//     2 + 1 + 5 = 8
//
// Move one position:
//
// Remove 2
// Add 1
//
//     8 - 2 + 1 = 7
//
// Next:
//
//     7 - 1 + 3 = 9
//
// We reuse the previous answer.
//
// ------------------------------------------------------------
//
// This is the key idea of:
//
//     SLIDING WINDOW
//
// ------------------------------------------------------------
//
// Naive:
//
//     O(n × k)
//
// Optimized:
//
//     O(n)
//
// ------------------------------------------------------------
//
// This is one of the most important patterns
// you will use later in DSA.
//
// ============================================================


// ============================================================
// Q13 | VERY HARD | When should the loop stop?
// ============================================================
//
// You have:
//
//     n = 1000000
//
// and need to find the first number divisible by:
//
//     7, 11 and 13
//
// ------------------------------------------------------------
//
// Don't blindly check every number.
//
// A number divisible by all three must be divisible by:
//
//     LCM(7, 11, 13)
//
// Since they are pairwise coprime:
//
//     7 × 11 × 13 = 1001
//
// Therefore the first positive answer is:
//
//     1001
//
// ------------------------------------------------------------
//
// The naive solution:
//
//     for (int i = 1; i <= n; i++)
//
// is unnecessary.
//
// Mathematics gives the answer directly.
//
// ------------------------------------------------------------
//
// TIME:
//
//     O(1)
//
// ------------------------------------------------------------
//
// IMPORTANT:
//
// Optimization sometimes comes from mathematics,
// not from clever C++.
//
// ============================================================


// ============================================================
// Q14 | FINAL CHALLENGE | The DSA Mindset
// ============================================================
//
// You receive an array:
//
//     3 -2 5 -1 6 -3 2
//
// Find the maximum sum of a contiguous section.
//
// Don't use nested loops.
//
// Don't calculate every possible subarray.
//
// ------------------------------------------------------------
//
// The key question:
//
// "What information from the previous position
//  is actually useful?"
//
// Maintain:
//
//     current best ending here
//     global best
//
// ------------------------------------------------------------
//
// SOLUTION:
//
// int current = 0;
// int best = a[0];
//
// for (int x : a) {
//
//     current = max(x, current + x);
//
//     best = max(best, current);
// }
//
// cout << best;
//
// ------------------------------------------------------------
//
// WHY?
//
// At every element we ask:
//
//     Is it better to:
//
//     1. start a new subarray here?
//
//     OR
//
//     2. continue the previous subarray?
//
// That gives:
//
//     current = max(x, current + x)
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
// The naive nested-loop approach is O(n²).
//
// This solution is O(n).
//
// The important lesson isn't the formula.
//
// It is this:
//
//     Keep only the state that can affect
//     the future answer.
//
// THAT is a major DSA skill.
//
// ============================================================

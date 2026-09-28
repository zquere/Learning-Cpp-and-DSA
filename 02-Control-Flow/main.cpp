#include <iostream>
#include <string>
using namespace std;


// ============================================================
//                    C++ CONTROL FLOW
// ============================================================
//
//  Fundamentals taught me how to store and work with data.
//
//  Now I need to control what the program actually does.
//
//  Sometimes I want to:
//      -> make a decision
//      -> choose between multiple paths
//      -> repeat something
//      -> stop a loop
//      -> skip one iteration
//
//  That's what control flow is about.
//
// ============================================================


// ============================================================
// 01. IF STATEMENT
// ============================================================
//
// if checks a condition.
//
//     if (condition) {
//         code
//     }
//
// The condition is evaluated first.
// If it is true, the block runs.
// If it is false, the block is skipped.
//
// ============================================================

int main() {

    int age = 20;

    if (age >= 18) {
        cout << "Adult" << endl;
    }

    // Think about what happened here:
    //
    //     age >= 18
    //     20 >= 18
    //          ↓
    //        true
    //
    // The comparison produces a bool value.
    // if uses that result to decide what to execute.


    // ============================================================
    // 02. IF / ELSE
    // ============================================================
    //
    // With if alone, I only have a block that runs when
    // the condition is true.
    //
    // else gives me the second path.
    //
    // ============================================================

    int number = 15;

    if (number > 0) {
        cout << "Positive" << endl;
    }
    else {
        cout << "Zero or negative" << endl;
    }

    // Only ONE of these blocks executes.
    //
    // number = 15
    //     ↓
    // number > 0
    //     ↓
    //   true
    //     ↓
    // first block runs
    //
    // The else block is skipped.


    // ============================================================
    // 03. = vs ==
    // ============================================================
    //
    // This is an important distinction in C++.
    //
    //     =   assignment
    //     ==  comparison
    //
    // They look similar, but they do completely different things.
    // ============================================================

    int x = 10;       // put 10 into x

    if (x == 10) {    // ask: "is x equal to 10?"
        cout << "x is 10" << endl;
    }

    // Don't accidentally write:
    //
    //     if (x = 10)
    //
    // That assigns 10 to x.
    //
    // It is NOT the same thing as:
    //
    //     if (x == 10)


    // ============================================================
    // 04. ELSE-IF
    // ============================================================
    //
    // When there are several possible conditions,
    // I can check them one after another.
    //
    // C++ goes from top to bottom and stops at the first
    // condition that is true.
    //
    // ============================================================

    int marks = 82;

    if (marks >= 90) {
        cout << "Grade A" << endl;
    }
    else if (marks >= 75) {
        cout << "Grade B" << endl;
    }
    else if (marks >= 50) {
        cout << "Grade C" << endl;
    }
    else {
        cout << "Fail" << endl;
    }

    // marks = 82
    //
    // 82 >= 90   -> false
    // 82 >= 75   -> true
    //
    // So "Grade B" runs.
    //
    // The remaining conditions are not checked.


    // ============================================================
    // 05. WHY ORDER MATTERS
    // ============================================================
    //
    // The order of conditions can completely change the result.
    //
    // This is WRONG for the grading system above:
    //
    //     if (marks >= 50)
    //         Grade C
    //
    //     else if (marks >= 75)
    //         Grade B
    //
    // Why?
    //
    // 82 >= 50 is already true.
    //
    // So C++ would never reach the >= 75 condition.
    //
    // More specific conditions should come before broader ones.
    //
    // ============================================================


    // ============================================================
    // 06. NESTED IF
    // ============================================================
    //
    // An if can contain another if.
    //
    // The inner decision is only reached when the outer
    // decision allows execution to reach it.
    //
    // ============================================================

    int userAge = 20;
    bool hasID = true;

    if (userAge >= 18) {

        cout << "Age requirement passed." << endl;

        if (hasID) {
            cout << "ID verified." << endl;
        }
    }

    // The flow is:
    //
    //     age >= 18 ?
    //          |
    //        yes
    //          ↓
    //      hasID ?
    //          |
    //        yes
    //          ↓
    //     ID verified


    // ============================================================
    // 07. LOGICAL AND &&
    // ============================================================
    //
    // Sometimes one condition isn't enough.
    //
    // && means:
    //
    //     BOTH conditions must be true.
    //
    // ============================================================

    int checkAge = 25;

    if (checkAge >= 18 && checkAge <= 60) {
        cout << "Age is between 18 and 60." << endl;
    }

    // Think:
    //
    //     condition 1 && condition 2
    //
    //     true  && true   -> true
    //     true  && false  -> false
    //     false && true   -> false
    //     false && false  -> false
    //
    // AND needs both sides to be true.


    // ============================================================
    // 08. LOGICAL OR ||
    // ============================================================
    //
    // || means:
    //
    //     at least ONE condition must be true.
    //
    // ============================================================

    int day = 6;

    if (day == 6 || day == 7) {
        cout << "Weekend" << endl;
    }

    // 6 == 6 -> true
    //
    // Once one side of OR is true, the complete expression
    // is already true.


    // ============================================================
    // 09. LOGICAL NOT !
    // ============================================================
    //
    // ! reverses a boolean value.
    //
    //     true  -> false
    //     false -> true
    //
    // ============================================================

    bool isRaining = false;

    if (!isRaining) {
        cout << "No rain." << endl;
    }

    // isRaining is false.
    //
    // !isRaining becomes true.
    //
    // So the if block runs.


    // ============================================================
    // 10. SHORT-CIRCUIT EVALUATION
    // ============================================================
    //
    // C++ can stop evaluating a logical expression early.
    //
    // With &&:
    //
    //     false && anything
    //
    // must be false.
    //
    // With ||:
    //
    //     true || anything
    //
    // must be true.
    //
    // This is called short-circuit evaluation.
    //
    // ============================================================

    int value = 10;

    if (value != 0 && 100 / value > 5) {
        cout << "Condition passed." << endl;
    }

    // The first condition checks that value isn't zero.
    //
    // Only after that is true do we evaluate:
    //
    //     100 / value
    //
    // This kind of ordering becomes useful when one condition
    // protects an operation that comes after it.


    // ============================================================
    // 11. SWITCH
    // ============================================================
    //
    // switch is useful when one value needs to be compared
    // against several exact values.
    //
    // ============================================================

    int choice = 2;

    switch (choice) {

        case 1:
            cout << "Option 1" << endl;
            break;

        case 2:
            cout << "Option 2" << endl;
            break;

        case 3:
            cout << "Option 3" << endl;
            break;

        default:
            cout << "Invalid option" << endl;
    }

    // choice = 2
    //
    // C++ finds case 2.
    //
    // break then exits the switch.
    //
    // Without break, execution can continue into the next case.


    // ============================================================
    // 12. SWITCH FALL-THROUGH
    // ============================================================
    //
    // Forgetting break doesn't stop the program.
    // Instead, execution continues into the following cases.
    //
    // I'm showing it here deliberately because it is important
    // to understand what break actually does.
    //
    // ============================================================

    int test = 1;

    switch (test) {

        case 1:
            cout << "One" << endl;

        case 2:
            cout << "Two" << endl;

        case 3:
            cout << "Three" << endl;
    }

    // Output:
    //
    // One
    // Two
    // Three
    //
    // test matches case 1.
    //
    // There is no break, so execution keeps going.


    // ============================================================
    // 13. TERNARY OPERATOR
    // ============================================================
    //
    // The ternary operator is a compact if/else expression.
    //
    //     condition ? true_value : false_value
    //
    // ============================================================

    int studentAge = 20;

    string status =
        (studentAge >= 18) ? "Adult" : "Minor";

    cout << status << endl;

    // This is basically a shorter version of:
    //
    //     if (studentAge >= 18) {
    //         status = "Adult";
    //     }
    //     else {
    //         status = "Minor";
    //     }
    //
    // It is useful for small decisions.
    // I shouldn't use it to hide complicated logic.


    // ============================================================
    //                         LOOPS
    // ============================================================
    //
    // Conditions let the program choose.
    //
    // Loops let the program repeat.
    //
    // ============================================================


    // ============================================================
    // 14. FOR LOOP
    // ============================================================
    //
    // A for loop has three important parts:
    //
    //     for (start; condition; update)
    //
    // Example:
    //
    //     for (int i = 1; i <= 5; i++)
    //
    // ============================================================

    for (int i = 1; i <= 5; i++) {

        cout << i << " ";
    }

    cout << endl;

    // The execution order is:
    //
    //     int i = 1
    //          ↓
    //     i <= 5 ?
    //          ↓
    //        body
    //          ↓
    //        i++
    //          ↓
    //     check again
    //
    // The initialization happens once.
    // The condition and update happen repeatedly.


    // ============================================================
    // 15. FOR LOOP - DIFFERENT UPDATE
    // ============================================================
    //
    // The update doesn't have to be i++.
    //
    // ============================================================

    for (int i = 0; i <= 10; i += 2) {

        cout << i << " ";
    }

    cout << endl;

    // Output:
    //
    // 0 2 4 6 8 10
    //
    // i += 2 means:
    //
    //     i = i + 2


    // ============================================================
    // 16. < vs <=
    // ============================================================
    //
    // These small symbols can change how many times a loop runs.
    //
    // ============================================================

    for (int i = 0; i < 5; i++) {
        cout << i << " ";
    }

    cout << endl;

    // 0 1 2 3 4
    //
    // Five iterations.

    for (int i = 0; i <= 5; i++) {
        cout << i << " ";
    }

    cout << endl;

    // 0 1 2 3 4 5
    //
    // Six iterations.
    //
    // This kind of mistake is called an off-by-one error.


    // ============================================================
    // 17. WHILE LOOP
    // ============================================================
    //
    // A while loop checks its condition before entering the body.
    //
    // ============================================================

    int count = 1;

    while (count <= 5) {

        cout << count << " ";

        count++;
    }

    cout << endl;

    // Flow:
    //
    //     check
    //       ↓
    //     true
    //       ↓
    //     body
    //       ↓
    //     update
    //       ↓
    //     check again
    //
    // Once count becomes 6:
    //
    //     6 <= 5 -> false
    //
    // The loop stops.


    // ============================================================
    // 18. INFINITE LOOP
    // ============================================================
    //
    // A loop needs some way to eventually become false.
    //
    // This would be dangerous:
    //
    //     while (count <= 5) {
    //         cout << count;
    //     }
    //
    // count never changes.
    //
    // So the condition stays true forever.
    //
    // This is an infinite loop.
    //
    // I won't run it here.
    //


    // ============================================================
    // 19. DO-WHILE
    // ============================================================
    //
    // while:
    //
    //     check -> body
    //
    // do-while:
    //
    //     body -> check
    //
    // So do-while always executes at least once.
    //
    // ============================================================

    int n = 10;

    do {

        cout << "This runs once." << endl;

        n++;

    } while (n < 5);

    // n is already 10.
    //
    // 10 < 5 is false.
    //
    // But the message still prints because the body
    // runs before the condition is checked.


    // ============================================================
    // 20. BREAK
    // ============================================================
    //
    // break completely leaves the loop.
    //
    // ============================================================

    for (int i = 1; i <= 10; i++) {

        if (i == 6) {
            break;
        }

        cout << i << " ";
    }

    cout << endl;

    // Output:
    //
    // 1 2 3 4 5
    //
    // When i becomes 6:
    //
    //     break
    //       ↓
    //     leave loop
    //
    // There is no next iteration.


    // ============================================================
    // 21. CONTINUE
    // ============================================================
    //
    // continue does NOT leave the loop.
    //
    // It skips the rest of the current iteration.
    //
    // ============================================================

    for (int i = 1; i <= 5; i++) {

        if (i == 3) {
            continue;
        }

        cout << i << " ";
    }

    cout << endl;

    // Output:
    //
    // 1 2 4 5
    //
    // When i == 3:
    //
    //     continue
    //         ↓
    //     skip this iteration
    //         ↓
    //     go to next iteration


    // ============================================================
    // 22. BREAK vs CONTINUE
    // ============================================================
    //
    //     break
    //         -> leave the loop
    //
    //     continue
    //         -> skip this iteration
    //
    // This difference becomes very important in larger programs.


    // ============================================================
    // 23. NESTED LOOPS
    // ============================================================
    //
    // A nested loop is simply a loop inside another loop.
    //
    // The inner loop completes all of its iterations
    // for every iteration of the outer loop.
    //
    // ============================================================

    for (int row = 1; row <= 3; row++) {

        for (int column = 1; column <= 4; column++) {

            cout << "* ";
        }

        cout << endl;
    }

    // Think of it as a grid:
    //
    // row 1 -> 4 columns
    // row 2 -> 4 columns
    // row 3 -> 4 columns
    //
    // Total inner-loop executions:
    //
    //     3 × 4 = 12


    // ============================================================
    // 24. PATTERN PROGRAMMING
    // ============================================================
    //
    // Patterns are good practice for understanding nested loops.
    //
    // First, a simple triangle:
    //
    //     *
    //     * *
    //     * * *
    //     * * * *
    //
    // ============================================================

    for (int row = 1; row <= 4; row++) {

        for (int column = 1; column <= row; column++) {

            cout << "* ";
        }

        cout << endl;
    }

    // The important relationship is:
    //
    //     row 1 -> 1 star
    //     row 2 -> 2 stars
    //     row 3 -> 3 stars
    //     row 4 -> 4 stars
    //
    // That's why:
    //
    //     column <= row
    //
    // works.


    // ============================================================
    // 25. NUMBER PATTERN
    // ============================================================

    for (int row = 1; row <= 5; row++) {

        for (int column = 1; column <= row; column++) {

            cout << column << " ";
        }

        cout << endl;
    }

    // Output:
    //
    // 1
    // 1 2
    // 1 2 3
    // 1 2 3 4
    // 1 2 3 4 5


    // ============================================================
    // 26. REVERSE PATTERN
    // ============================================================
    //
    // Same idea, but now the number of stars decreases.
    //
    // ============================================================

    for (int row = 5; row >= 1; row--) {

        for (int column = 1; column <= row; column++) {

            cout << "* ";
        }

        cout << endl;
    }


    // ============================================================
    // 27. LOOP + IF
    // ============================================================
    //
    // The real power starts when I combine concepts.
    //
    // Example:
    //
    // Print only even numbers from 1 to 10.
    //
    // ============================================================

    for (int i = 1; i <= 10; i++) {

        if (i % 2 == 0) {
            cout << i << " ";
        }
    }

    cout << endl;

    // The loop gives us:
    //
    //     1 2 3 4 5 6 7 8 9 10
    //
    // The if filters them.
    //
    //     i % 2 == 0
    //
    // means the remainder after division by 2 is zero.


    // ============================================================
    // 28. LOOP + IF + LOGICAL OPERATOR
    // ============================================================
    //
    // Print numbers divisible by both 3 and 5.
    //
    // ============================================================

    for (int i = 1; i <= 30; i++) {

        if (i % 3 == 0 && i % 5 == 0) {
            cout << i << " ";
        }
    }

    cout << endl;

    // Now several ideas are working together:
    //
    //     for
    //     if
    //     %
    //     &&
    //
    // This is closer to how actual programming problems look.


    // ============================================================
    // 29. TRACE THE PROGRAM
    // ============================================================
    //
    // One of the best debugging skills is being able to
    // execute code mentally.
    //
    // Example:
    //
    //     total = 0
    //
    //     i = 1 -> total = 1
    //     i = 2 -> total = 3
    //     i = 3 -> total = 6
    //     i = 4 -> total = 10
    //     i = 5 -> total = 15
    //
    // ============================================================

    int total = 0;

    for (int i = 1; i <= 5; i++) {

        total = total + i;
    }

    cout << "Total: " << total << endl;


    // ============================================================
    // 30. CONTROL FLOW IN ONE PICTURE
    // ============================================================
    //
    // Decision:
    //
    //             condition
    //             /      \
    //          true      false
    //            ↓          ↓
    //          path       path
    //
    //
    // Loop:
    //
    //             condition
    //                ↓
    //              true
    //                ↓
    //              body
    //                ↓
    //             update
    //                ↓
    //             condition
    //
    //                false
    //                  ↓
    //                exit
    //
    //
    // Once I understand these two ideas, most control-flow
    // syntax becomes much easier to reason about.
    //
    // ============================================================


    // ============================================================
    // 31. THINGS I NEED TO WATCH OUT FOR
    // ============================================================
    //
    // [ ] = vs ==
    //
    // [ ] accidental semicolon after if
    //
    // [ ] wrong else-if order
    //
    // [ ] forgetting break in switch
    //
    // [ ] infinite loops
    //
    // [ ] off-by-one errors
    //
    // [ ] confusing break with continue
    //
    // [ ] forgetting to update a while-loop variable
    //
    // [ ] making a condition harder than it needs to be
    //
    // ============================================================


    // ============================================================
    // 32. WHAT I SHOULD BE ABLE TO DO NOW
    // ============================================================
    //
    // After this section, I should be able to:
    //
    //     -> make decisions with if / else
    //     -> build multiple conditions with else-if
    //     -> combine conditions using &&, || and !
    //     -> understand short-circuit evaluation
    //     -> use switch and understand fall-through
    //     -> choose between for, while and do-while
    //     -> stop loops with break
    //     -> skip iterations with continue
    //     -> trace nested loops
    //     -> build basic patterns
    //     -> combine loops and conditions
    //     -> find common control-flow bugs
    //
    // The important part is not memorizing the syntax.
    //
    // I should be able to look at a piece of code and explain:
    //
    // ============================================================


    return 0;
}
```

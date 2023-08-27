.data
takeinput: .asciiz "Enter the number you want to find factorial of: "
result: .asciiz "The factorial is: "

.text
.globl main
main:
    # Prompt the user to enter a number
    li $v0, 4
    la $a0, takeinput
    syscall

    # Read the input
    li $v0, 5
    syscall

    # Save the input in $t0 and initialize $t1 to 1
    move $t0, $v0
    li $t1, 1

loop:
    # Multiply $t1 by $t0
    mul $t1, $t1, $t0

    # Decrement $t0
    sub $t0, $t0, 1

    # Check if $t0 is not equal to 1
    bne $t0, $zero, loop

    # Display the result
    li $v0, 4
    la $a0, result
    syscall

    li $v0, 1
    move $a0, $t1
    syscall

    # Exit the program
    li $v0, 10
    syscall

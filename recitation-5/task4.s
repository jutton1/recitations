.text

.globl main
main:
    # Make space on the stack for the return address
    addi $sp, $sp, -4
    sw $ra, 0($sp)

    # Stores input values into the s registers
    li $s0, 1
    li $s1, 2

    # Move values to argument registers
    move $a0, $s0
    move $a1, $s1

    # Jump and link to foo
    jal foo

    # Prints the result
    move $a0, $v0
    li $v0, 1
    syscall

    # Put stack back to normal
    lw $ra, 0($sp)
    addi $sp, $sp, 4

    # Go back to wherever we were before
    jr $ra

foo:
    addi $sp, $sp, -16
    sw $ra, 0($sp)
    sw $s0, 4($sp)
    sw $s1, 8($sp)
    
    # Check if a0 + a1 > 10
    add $t2, $a0, $a1
    li $t5, 10
    bgt $t2, $t5, _done

    # Increment Arguments
    addi $a0, $a0, 1
    addi $a1, $a1, 1

    # Saving the sum onto the stack
    sw $t2, 12($sp)
    jal foo

    # Restoring value of $t2
    lw $t2, 12($sp)

    # Adding the results together
    add $t2, $t2, $v0

_done:
    # Base Case: return $a0 + $a1
    move $v0, $t2

    # Puts the stack back to normal
    lw $s1, 8($sp)
    lw $s0, 4($sp)
    lw $ra, 0($sp)
    addi $sp, $sp, 16

    jr $ra
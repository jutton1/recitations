# code section
.text

# ======================== start of function: main
# int main() {
main:
    # int i=1;
    li $t0, 1

# while (i<=10) {
_loop:
    # if t0 is above 10, branch out of loop
    bgt $t0, 10, _endloop

    # int sq = i*i;
    # compute t0*t0 and put result in t1
    mul $t1, $t0, $t0

    # printf("%d %d\n",i,sq); # we’ll do this in four stages

    # (print i)
    li $v0, 1
    move $a0, $t0
    syscall

    # (print space)
    li $v0, 4
    move $a0, str_space
    syscall


    # (print sq)
    li $v0, 1
    move $a0, $t1
    syscall


    # (print newline)
    li $v0, 4
    move $a0, str_newline
    syscall


    # i++;
    # increment t0
    addi $t0, $t0, 1

    # } // end of loop
    # branch to top of loop unconditionally
    j _loop

_endloop:
    # return 0;
    li $v0, 0   # doesn't really matter as SPIM loads 10 into it anyways.
    jr ra

# ======================== end of function: main

# data section
.data
    # a literal space string for printing
    str_space: .asciiz " "
    # a literal newline string for printing
    str_newline: .asciiz "\n" 
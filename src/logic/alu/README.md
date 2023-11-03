# Arithmetic logic unit
The alu is the component of the cpu that performs all the arithmetic and logic operations on data present in the input registers.

## Control
The control unit will send signals to the alu to tell it what operation to perform.

The following tables indicates what operation will be executed given a control signal.

| Control value | Binary control value| Operation |
|-|-|-|
| 0|000000|[Bitwise and](#BitwiseAND)|
| 1|000001|[Bitwise or](#BitwiseOR)|
| 2|000010|[Bitwise xor](#BitwiseXOR)|
| 3|000011|[Bitwise not](#BitwiseNOT)|
| 4|000100|[Bitwise nand](#BitwiseNAND)|
| 5|000101|[Bitwise nor](#BitwiseNOR)|
| 6|000110|[Bitwise xnor](#BitwiseXNOR)|
| 7|000111|[Logical shift 0 left](#Logical-shift-0-left)|
| 8|001000|[Logical shift 0 right](#Logical-shift-0-right)|
| 9|001001|[Logical shift 1 left](#Logical-shift-1-left)|
|10|001010|[Logical shift 1 right](#Logical-shift-1-right)|
|11|001011|[Rotate left](#Rotate-left)|
|12|001100|[Rotate right](#Rotate-right)|
|13|001101|[Rotate left trough carry](#Rotate-trough-carry-left)|
|14|001110|[Rotate right trough carry](#Rotate-trough-carry-right)|


## Arithmetic
### Add
#### 1.1.Full-adder
A full adder takes 2 bits (A and B) and a carry in (Cin) bit. It computes the sum (S) and the carry out (Cout) bit.
![Full adder](https://upload.wikimedia.org/wikipedia/commons/a/a9/Full-adder.svg)

#### 1.2.Ripple adder
By connecting the carry out of one full adder to the carry in of the next, we can daisy chain full adders until we have an n-bit adder.
![Ripple adder](https://upload.wikimedia.org/wikipedia/commons/5/5d/4-bit_ripple_carry_adder.svg)
This adder however has the downside that all the bits will be sequentially added.

## Logic
### BitwiseAnd
### BitwiseOR
### BitwiseXOR
### BitwiseNOT
### BitwiseNAND
### BitwiseNOR
### BitwiseXNOR

## Shifts
### Logical-shift-0
#### Logical-shift-0-left
![](https://upload.wikimedia.org/wikipedia/commons/5/5c/Rotate_left_logically.svg)
#### Logical-shift-0-right
![](https://upload.wikimedia.org/wikipedia/commons/6/64/Rotate_right_logically.svg)
### Logical-shift-1
#### Logical-shift-1-left
This is the same operation as the [Logical shift 0 left](#Logical-shift-0-left). But we shift in a 1 instead of a 0.
#### Logical-shift-1-right
This is the same operation as the [Logical shift 0 right](#Logical-shift-0-right). But we shift in a 1 instead of a 0.

### Rotate
#### Rotate-left
![](https://upload.wikimedia.org/wikipedia/commons/0/09/Rotate_left.svg)
#### Rotate-right
![](https://upload.wikimedia.org/wikipedia/commons/3/37/Rotate_right.svg)

### Rotate-trough-carry
#### Rotate-trough-carry-left
![](https://upload.wikimedia.org/wikipedia/commons/7/71/Rotate_left_through_carry.svg)
#### Rotate-trough-carry-right
![](https://upload.wikimedia.org/wikipedia/commons/2/27/Rotate_right_through_carry.svg)
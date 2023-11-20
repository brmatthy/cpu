# Arithmetic logic unit
The alu is the component of the cpu that performs all the arithmetic and logic operations on data present in the input registers.

## NodeTypes
To make the alu operatable for any n-bit register it takes a list of inA, inB and out nodeTypes.
All the operations also use these lists, to make things generic.
See `src/logic/base/NodeTypeGetter.cpp` for a possible list of the in and output nodes.

## Control
The control unit will send signals to the alu to tell it what operation to perform.

The following tables indicates what operation will be executed given a control signal.

| Control value | Binary control value| Operation |
|-|-|-|
| 0|00000|[Bitwise and](#BitwiseAND)|
| 1|00001|[Bitwise or](#BitwiseOR)|
| 2|00010|[Bitwise xor](#BitwiseXOR)|
| 3|00011|[Bitwise not](#BitwiseNOT)|
| 4|00100|[Bitwise nand](#BitwiseNAND)|
| 5|00101|[Bitwise nor](#BitwiseNOR)|
| 6|00110|[Bitwise xnor](#BitwiseXNOR)|
| 7|00111|[Logical shift 0 left](#Logical-shift-0-left)|
| 8|01000|[Logical shift 0 right](#Logical-shift-0-right)|
| 9|01001|[Logical shift 1 left](#Logical-shift-1-left)|
|10|01010|[Logical shift 1 right](#Logical-shift-1-right)|
|11|01011|[Rotate left](#Rotate-left)|
|12|01100|[Rotate right](#Rotate-right)|
|13|01101|[Integer addition](#Add)|
|14|01110|[Bitwise and](#BitwiseAND)|
|15|01111|[Bitwise and](#BitwiseAND)|

Operation 14 and 15 should not be used. They simply have the and operation there as a placeholder. Later other operations might be added.
- [ ] Integer negation
- [ ] Integer subtraction
- [ ] Integer multiplication
- [ ] Integer division
- [ ] Floating point addition
- [ ] Floating point subtraction
- [ ] Floating point multiplication
- [ ] Floating point division


## Arithmetic
### Add
#### 1.1.Full-adder
> - IN_FULLADD_A
> - IN_FULLADD_B
> - IN_CARRY
> - OUT_FULLADD_S
> - OUT_CARRY

A full adder takes 2 bits (A and B) and a carry in (Cin) bit. It computes the sum (S) and the carry out (Cout) bit.
![Full adder](https://upload.wikimedia.org/wikipedia/commons/a/a9/Full-adder.svg)

#### 1.2.Ripple adder
> - n input bits A
> - n input bits B
> - n output bits
> - IN_CARRY
> - OUT_CARRY

By connecting the carry out of one full adder to the carry in of the next, we can daisy chain full adders until we have an n-bit adder.
![Ripple adder](https://upload.wikimedia.org/wikipedia/commons/5/5d/4-bit_ripple_carry_adder.svg)
This adder however has the downside that all the bits will be sequentially added.

## Logic
### BitwiseAnd
> - n input bits A
> - n input bits B
> - n output bits

Takes 2 n-long inputs and performs the and operation for each of the input bits respectively. The result is mad available at the respective output bit. (also n-long).
### BitwiseOR
> - n input bits A
> - n input bits B
> - n output bits

Takes 2 n-long inputs and performs the or operation for each of the input bits respectively. The result is made available at the respective output bit. (also n-long).
### BitwiseXOR
> - n input bits A
> - n input bits B
> - n output bits

Takes 2 n-long inputs and performs the xor operation for each of the input bits respectively. The result is made available at the respective output bit. (also n-long).
### BitwiseNOT
> - n input bits
> - n output bits

Takes an n input bits and performs the not operation for each of the input bits. The result is made available at the respective output bit. (also n-long).
### BitwiseNAND
> - n input bits A
> - n input bits B
> - n output bits

Takes 2 n-long inputs and performs the nand operation for each of the input bits respectively. The result is made available at the respective output bit. (also n-long).
### BitwiseNOR
> - n input bits A
> - n input bits B
> - n output bits

Takes 2 n-long inputs and performs the nor operation for each of the input bits respectively. The result is made available at the respective output bit. (also n-long).
### BitwiseXNOR
> - n input bits A
> - n input bits B
> - n output bits

Takes 2 n-long inputs and performs the xnor operation for each of the input bits respectively. The result is made available at the respective output bit. (also n-long).

## Shifts
### Logical-shift-0
#### Logical-shift-0-left
> - n input bits
> - n output bits

![](https://upload.wikimedia.org/wikipedia/commons/5/5c/Rotate_left_logically.svg)
#### Logical-shift-0-right
> - n input bits
> - n output bits

![](https://upload.wikimedia.org/wikipedia/commons/6/64/Rotate_right_logically.svg)
### Logical-shift-1
#### Logical-shift-1-left
> - n input bits
> - n output bits


This is the same operation as the [Logical shift 0 left](#Logical-shift-0-left). But we shift in a 1 instead of a 0.
#### Logical-shift-1-right
> - n input bits
> - n output bits


This is the same operation as the [Logical shift 0 right](#Logical-shift-0-right). But we shift in a 1 instead of a 0.

### Rotate
#### Rotate-left
> - n input bits
> - n output bits


![](https://upload.wikimedia.org/wikipedia/commons/0/09/Rotate_left.svg)
#### Rotate-right
> - n input bits
> - n output bits


![](https://upload.wikimedia.org/wikipedia/commons/3/37/Rotate_right.svg)

### Rotate-trough-carry
#### Rotate-trough-carry-left
> - n input bits
> - n output bits


![](https://upload.wikimedia.org/wikipedia/commons/7/71/Rotate_left_through_carry.svg)
#### Rotate-trough-carry-right
> - n input bits
> - n output bits


![](https://upload.wikimedia.org/wikipedia/commons/2/27/Rotate_right_through_carry.svg)

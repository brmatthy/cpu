# Data
All the circuitry that is used to store bits is defined here.

### DLatch
> - IN_DLATCH_DATA
> - IN_DLATCH_CLK
> - OUT_DLATCH
> - OUT_DLATCH_INV

This is an implementation of a [data latch](https://en.wikipedia.org/wiki/Flip-flop_(electronics)#Gated_D_latch)

![](https://www.allaboutcircuits.com/uploads/articles/internal-logic-d-latch.jpg)
where E is the clock.

When the clock is high (a.k.a. 1) the data (D) can be stored. One can always read from the outputs, but only when the clock is low the output will be stable.

### DFlipFlop
> - IN_DFLIPFLOP_DATA
> - IN_DFLIPFLOP_CLK
> - OUT_DFLIPFLOP
> - OUT_DFLIPFLOP_INV

This is simply 2 [dlatches](#DLatch) in a row with the clock inverted for the second dlatch. This gives us the advantage that in a cycle we can store a bit, and that bit will be stable available during the entirety of the next cycle. We say that a new cycle starts when the clock becomes low.

### Register
Just as with the [ALU](../alu/README.md)
We will use a list of input and output nodes.
> - n input bits
> - n output bits
> - IN_REG_CLK

A register is simply an n-long array of [D flip flops](#DFLIPFLOP). The clock controls those flip flops.
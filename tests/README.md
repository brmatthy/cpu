# Tests
## Implemented tests
### Logic
#### Base
Even to that these components are not yet tested they are used extensively everywhere. If they would have flaws other tests would have failed.
- [ ] Logic
- [ ] Node
#### Gates
See `tests/test_gates.cpp`.
- [x] And
- [x] Or
- [x] Xor
- [x] Not
- [x] Nand
- [x] Nor
- [x] Xnor
#### Data
See `tests/test_data.cpp`.
- [x] DLatch
- [x] DFlipFlop
- [x] Register
#### ALU
See `tests/test_alu.cpp`.
- [ ] Alu _(Tested whether the control bits select the correct function to execute.)_ In Progress
- [ ] FullAdder
- [ ] RippleAdder
- [ ] BitwiseAnd _(Simple test by the Alu testing)_
- [ ] BitwiseOr _(Simple test by the Alu testing)_
- [ ] BitwiseXor _(Simple test by the Alu testing)_
- [ ] BitwiseNot _(Simple test by the Alu testing)_
- [ ] BitwiseXnor _(Simple test by the Alu testing)_
- [ ] RotateL
- [ ] RotateR
- [ ] ShiftL0
- [ ] ShiftR0
- [ ] ShiftL1
- [ ] ShiftR1
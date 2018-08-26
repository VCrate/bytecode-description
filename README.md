# Bytecode Description

Tool to read and write to an instruction
Describe the format

## Formats

### V1

Instructions are 4 bytes long.

```
| 0| 1| 2| 3| 4| 5| 6| 7| 8| 9|10|11|12|13|14|15|16|17|18|19|20|21|22|23|24|25|26|27|28|29|30|31|
|-----------------------|-----------------------------------|-----------------------------------|
|    Instruction ID     |           Argument 12A            |           Argument 12B            |
|    Instruction ID     |                              Argument 24                              |
```

**Argument 24bits**
```
| 0| 1| 2| 3| 4| 5| 6| 7| 8| 9|10|11|12|13|14|15|16|17|18|19|20|21|22|23|
|  Type  | Register  |                   Displacement                   | // case Type in {0x01, 0x02, 0x03, 0x04}
|  Type  |                           Address                            | // case Type in {0x04}
|  Type  |                      Value (&3 = sign)                       | // case Type in {0x06}
```

**Argument 12bits**
```
| 0| 1| 2| 3| 4| 5| 6| 7| 8| 9|10|11|
|  Type  | Register  | Displacement | // case Type in {0x01, 0x02, 0x03, 0x04}
|  Type  |         Address          | // case Type in {0x04}
|  Type  |    Value (&3 = sign)     | // case Type in {0x06}
|  Type  |                          | // case Type in {0x05, 0x07}
```

**Register**

| Value | Register |
| ----- | -------- |
| 0x00 | A |
| 0x01 | B |
| 0x02 | C |
| 0x03 | D |
| 0x04 | E |
| 0x05 | F |
| 0x06 | G |
| 0x07 | H |
| 0x08 | I |
| 0x09 | J |
| 0x0A | K |
| 0x0B | L |
| 0x0C | Program counter (PC) |
| 0x0D | Flags (FG) |
| 0x0E | Base stack pointer (BP) |
| 0x0F | Stack pointer (SP) |

> Flags in `%FG` :  
>   - zero: 0x01
>   - greater: 0x02

**Type**

| Value | Readable | Writable | Addressable | Type |
| ----- | ---- | ---- | ---- | ---- |
| 0x00 | X | X |   | Register `%X` |
| 0x01 | X | X | X | Deferred Register `[%X]` |
| 0x02 | X | X | X | Displaced Deferred Register `[%X + disp]` |
| 0x03 | X | X | X | Displaced Deferred Register `[%X + disp]` (Displacement not included in the instruction) |
| 0x04 | X | X | X | Address `[X]` |
| 0x05 | X | X | X | Address `[X]` (Address not included in the instruction) |
| 0x06 | X |   |   | Value `X` |
| 0x07 | X |   |   | Value `X` (Value not included in the instruction) |

## Instruction Set

### Load / Compare

> `MOV a, b` : Load `b` into `a`  
> `a` need to be writable  
> `b` need to be readable

> `LEA a, b` : Load the address of `b` into `a`  
> `a` need to be writable  
> `b` need to be addressable

> `SWP a, b` : Swap the value of `a` and `b`  
> `a` and `b` need to be readable and writable  

> `CMP a, b` : Compare `a` and `b`, set the zero and the greater flag    
> `CMPU` is the unsigned version of `CMPU`  
> `a` and `b` need to be readable 

### Conversion

> `ITU a` : Convert a signed integer `a` to an unsigned integer
> `a` need to be readable and writable  

> `ITF a` : Convert a signed integer `a` to a float
> `a` need to be readable and writable  

> `UTI a` : Convert an unsigned integer `a` to a signed integer
> `a` need to be readable and writable  

> `UTF a` : Convert an unsigned integer `a` to a float
> `a` need to be readable and writable  

> `FTI a` : Convert a float `a` to a signed integer
> `a` need to be readable and writable  

> `FTU a` : Convert a float `a` to an unsigned integer
> `a` need to be readable and writable  

### Arithmetic Operations

> `ADD/ADDF a, b` : Add `b` to `a` (`a += b`)  
> `ADDF` is the float version of `ADD`  
> `a` need to be readable and writable  
> `b` need to be readable

> `SUB/SUBF a, b` : Subtract `b` to `a` (`a -= b`)  
> `SUBF` is the float version of `SUB`  
> `a` need to be readable and writable  
> `b` need to be readable

> `MOD/MODF a, b` : store the modulo between `a` and `b` into `a` (`a %= b`)  
> `MODF` is the float version of `MOD`  
> `a` need to be readable and writable  
> `b` need to be readable

> `MUL/MULU/MULF a, b` : Multiply `b` to `a` (`a *= b`)  
> `MULU` is the unsigned version of `MUL`  
> `MULF` is the float version of `MUL`  
> `a` need to be readable and writable  
> `b` need to be readable

> `DIV/DIVU/DIVF a, b` : Divide `b` to `a` (`a /= b`)  
> `DIVU` is the unsigned version of `DIV`  
> `DIVF` is the float version of `DIV`  
> `a` need to be readable and writable  
> `b` need to be readable

> `INC/INCF a` : Increment `a` (`a += 1`)  
> `INCF` is the float version of `INC`  
> `a` need to be readable and writable  

> `DEC/DECF a` : Decrement `a` (`a -= 1`)  
> `DECF` is the float version of `DEC`  
> `a` need to be readable and writable  

### Bitwise Operations

> `AND a, b` : bitwise 'and' `a &= b`  
> `a` need to be readable and writable  
> `b` need to be readable

> `OR a, b` : bitwise 'or' `a |= b`  
> `a` need to be readable and writable  
> `b` need to be readable

> `XOR a, b` : bitwise 'xor' `a ^= b`  
> `a` need to be readable and writable  
> `b` need to be readable

> `NOT a` : bitwise 'not' (one's complement) `a ~= a`  
> `a` need to be readable and writable  

> `SHL a, b` : left shift `a` by `b` into `a` (`a <<= b`)  
> `a` need to be readable and writable  
> `b` need to be readable

> `SHR a, b` : right shift `a` by `b` into `a` (`a >>= b`)  
> `a` need to be readable and writable  
> `b` need to be readable

> `RTL a, b` : left rotate `a` by `b` into `a` (`a <<<= b`)  
> `a` need to be readable and writable  
> `b` need to be readable

> `RTR a, b` : right rotate `a` by `b` into `a` (`a >>>= b`)  
> `a` need to be readable and writable  
> `b` need to be readable

### Control Flow

> `JMP a` : Jump to `a` (set `%PC` to `a`)  
> `a` need to be readable  

> `JMPE a` : Jump to `a` if the zero flag is 1 (set `%PC` to `a`)  
> `a` need to be readable  

> `JMPNE a` : Jump to `a` if the zero flag is 0 (set `%PC` to `a`)  
> `a` need to be readable  

> `JMPG a` : Jump to `a` if the greater flag is 1 (set `%PC` to `a`)  
> `a` need to be readable  

> `JMPGE a` : Jump to `a` if the zero flag or the greater flag is 1 (set `%PC` to `a`)  
> `a` need to be readable  

> `CALL a` : Push `%PC` to the stack then jump to `a` (set `%PC` to `a`)  
> `a` need to be readable  

> `RET` : Pop the stack into `%PC`  
> Inverse operation of `CALL`

> `HLT` : Halt the program with the return value in `%A`

### Stack operations

> `PUSH a` : Push `a` to the stack  
> `a` need to be readable  

> `POP a` : Pop the last value of the stack to `a`  
> `a` need to be writable  

> `ETR` : Start a new frame  
> Push `%BP` and set it to `%SP`

> `LVE` : Restore the last frame  
> Set `%SP` to `%BP` and Pop the stack into `%BP`  
> Inverse operation of `ETR`

### System

> `NEW a, b` : Allocate a block of `b` bytes and store the first address in `a`  
> `a` need to be writable  
> `b` need to be readable

> `DEL a` : Free a block previously allocated with `NEW`  
> `a` need to be readable  

### I/O

> `OUT a` : Print the first byte of `a` as a character to the standard output  
> `a` need to be readable  

> `DBG a` : Print `a` to the standard output  
> `a` need to be readable  

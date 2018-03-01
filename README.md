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
|  Type  |                      Value (&3 = sign)                       | // case Type in {0x04, 0x06}
|  Type  |                                                              | // case Type in {0x05, 0x07}
```

**Argument 12bits**
```
| 0| 1| 2| 3| 4| 5| 6| 7| 8| 9|10|11|
|  Type  | Register  | Displacement | // case Type in {0x01, 0x02, 0x03, 0x04}
|  Type  |    Value (&3 = sign)     | // case Type in {0x04, 0x06}
|  Type  |                          | // case Type in {0x05, 0x07}
```

**Register**

| Value | Registre |
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

**Type**

| Value | Type |
| ----- | ---- |
| 0x00 | Register `%X` |
| 0x01 | Deferred Register `[%X]` |
| 0x02 | Displaced Deferred Register `[%X + disp]` |
| 0x03 | Displaced Deferred Register `[%X + disp]` (Displacement not included in the instruction) |
| 0x04 | Address `[X]` |
| 0x05 | Address `[X]` (Address not included in the instruction) |
| 0x06 | Value `X` |
| 0x07 | Value `X` (Value not included in the instruction) |

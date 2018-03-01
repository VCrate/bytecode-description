# Binary Description

Tool to read and write to an instruction

## Formats

### V1

Instructions are 4 bytes long.

```
| 0| 1| 2| 3| 4| 5| 6| 7| 8| 9|10|11|12|13|14|15|16|17|18|19|20|21|22|23|24|25|26|27|28|29|30|31|
|-----------------------|-----------------------------------|-----------------------------------|
|    Instruction ID     |           Argument 12A            |           Argument 12B            |
|    Instruction ID     |                              Argument 24                              |
```

```
| 0| 1| 2| 3| 4| 5| 6| 7| 8| 9|10|11|
|  Type  | Register  | Displacement | // case Type in {0x01, 0x02, 0x03, 0x04}
|  Type  |    Value (&3 = sign)     | // case Type in {0x04, 0x06}
|  Type  |                          | // case Type in {0x05, 0x07}
```

# Задание 4
После создания переносимых объектных файлов в выводе `nm <filename.o>` видно следующее: \
file1.o
```output
0000000000000000 D global_var
                 U printf
0000000000000000 T print_from_file1
0000000000000004 d static_var
```
file2.o
```output
0000000000000000 D global_var
                 U printf
0000000000000000 T print_from_file2
                 U static_var
```
main.o
```output
                 U global_var
0000000000000000 T main
                 U printf
                 U print_from_file1
                 U print_from_file2
```
Здесь `D global_var` указывает на инициализированную глобальную переменную в файлах `file1` и `file2`. Для `main` она неопределена(`U`) \
`d static_var` в `file1` указывает на статическую переменную в файле `static_var`, доступную только оттуда
\
При попытке собрать программу возникает ошибка, указывающая на повторное объявление `global_var` в `file2`, а также на то что мы хотеим использовать `static_var` как глобальную переменную в `file2`, которая была определна как статическая и видна только в `file1`. 
\
Изменение этих ошибок следовательно привело к изменению таблицы символов `file2`. Теперь `global_var` неопределена в этом файле
file2
```output
                 U global_var
0000000000000000 T main
                 U printf
                 U print_from_file1
                 U print_from_file2

```
Вывод `objdump -t <filename>.o`
```output
file1.o:     формат файла elf64-x86-64

SYMBOL TABLE:
0000000000000000 l    df *ABS*  0000000000000000 file1.c
0000000000000000 l    d  .text  0000000000000000 .text
0000000000000000 l    d  .data  0000000000000000 .data
0000000000000004 l     O .data  0000000000000004 static_var
0000000000000000 l    d  .rodata        0000000000000000 .rodata
0000000000000000 g     O .data  0000000000000004 global_var
0000000000000000 g     F .text  000000000000003f print_from_file1
0000000000000000         *UND*  0000000000000000 printf


file2.o:     формат файла elf64-x86-64

SYMBOL TABLE:
0000000000000000 l    df *ABS*  0000000000000000 file2.c
0000000000000000 l    d  .text  0000000000000000 .text
0000000000000000 l    d  .rodata        0000000000000000 .rodata
0000000000000000 g     F .text  0000000000000023 print_from_file2
0000000000000000         *UND*  0000000000000000 global_var
0000000000000000         *UND*  0000000000000000 printf


main.o:     формат файла elf64-x86-64

SYMBOL TABLE:
0000000000000000 l    df *ABS*  0000000000000000 main.c
0000000000000000 l    d  .text  0000000000000000 .text
0000000000000000 l    d  .rodata        0000000000000000 .rodata
0000000000000000 g     F .text  000000000000003b main
0000000000000000         *UND*  0000000000000000 global_var
0000000000000000         *UND*  0000000000000000 printf
0000000000000000         *UND*  0000000000000000 print_from_file1
0000000000000000         *UND*  0000000000000000 print_from_file2
```
Здесь можно выделить, что функции храняться в сегменте `.text`, а глобалные и статические переменные в сегменете `.data`.
\
В выводе `strings program`
```output
/lib64/ld-linux-x86-64.so.2
__libc_start_main
__cxa_finalize
printf
libc.so.6
GLIBC_2.2.5
GLIBC_2.34
_ITM_deregisterTMCloneTable
__gmon_start__
_ITM_registerTMCloneTable
PTE1
u3UH
file1.c -> global_var = %d
file1.c -> static_var = %d
file2.c -> global_var = %d
main.c -> global_var = %d
;*3$"
GCC: (GNU) 14.2.1 20250128
file1.c
static_var
file2.c
main.c
_DYNAMIC
__GNU_EH_FRAME_HDR
_GLOBAL_OFFSET_TABLE_
__libc_start_main@GLIBC_2.34
_ITM_deregisterTMCloneTable
print_from_file2
_edata
_fini
printf@GLIBC_2.2.5
global_var
__data_start
__gmon_start__
__dso_handle
_IO_stdin_used
_end
print_from_file1
__bss_start
main
__TMC_END__
_ITM_registerTMCloneTable
__cxa_finalize@GLIBC_2.2.5
_init
.symtab
.strtab
.shstrtab
.interp
.note.gnu.property
.note.ABI-tag
.note.gnu.build-id
.gnu.hash
.dynsym
.dynstr
.gnu.version
.gnu.version_r
.rela.dyn
.rela.plt
.init
.text
.fini
.rodata
.eh_frame_hdr
.eh_frame
.init_array
.fini_array
.dynamic
.got
.got.plt
.data
.bss
.comment
```
Также содержатся строки из `printf()`:
```
file1.c -> global_var = %d
file1.c -> static_var = %d
file2.c -> global_var = %d
main.c -> global_var = %d
```

Вывод `objdump -x program`:
- `0000000000001040 g   F .text  0000000000000026   _start` указывает на адрес(`0000000000001040`), с которого начинается программа 
- `.text 00000196  0000000000001040  0000000000001040  00001040  2**4` - раздел `.text` расположенный по адресу `0000000000001040`, тут же расположен код программы(в том числе наши функции)
- `.data 00000018  0000000000004008  0000000000004008  00003008  2**3` - раздел `.data`, по адресу `0000000000004008`, здесь хранятся перменный, например, наша `global_var` (`0000000000004018 g     O .data  0000000000000004             global_var`)
- `.bss 00000008  0000000000004020  0000000000004020  00003020  2**0` - раздел `.bss`, по адресу `0000000000004020`, здесь хранятся неинициализированные глобальные переменные.
- `.rodata       00000073  0000000000002000  0000000000002000  00002000  2**2` - раздел `.rodata`, по адресу `0000000000002000`, здесь хранятся данные, доступные только для чтения, такие как строковые литералы и константы. 
- `NEEDED libc.so.6` - используется (динамически) библиотека `libc.so.6`

Вывод `objdump -x program` после статической компиляции становиться очень огромным (так как все необходимые библиотеки включаются в исполняемый файл). 


Почему global_var есть в .data, а static_var нет в таблице символов? \
`static_var` тоже есть в таблице символов:
```objdump -x program | egrep "static_var|global_var"
000000000000401c l     O .data  0000000000000004              static_var
0000000000004018 g     O .data  0000000000000004              global_var
```

# Задание 1(2)
В какой секции ELF-файла будет находиться global_var? `.data` \
В какой секции ELF-файла будет храниться uninitialized_global_var? `.bss` \
Где находится static_var? `.data` \
Где будет размещена global_point? `.data` \
Где будут расположены: \
- local_var из функции print_message? `stack` 
- static_local_var из той же функции? `.data` 

Где будет храниться auto_var из функции main? `stack` \
Где будет выделена память для dynamic_var? `heap` \
Где будет создана stack_point? `stack` 

# Задание 3
nm до связывания:
```main.o
                 U calculate_distance
                 U check_fuel
                 U __isoc99_scanf
0000000000000000 T main
                 U printf
                 U puts
                 U __stack_chk_fail
```
```navigation.o
0000000000000000 T calculate_distance
```
```fuel.o
0000000000000000 T check_fuel
```
В `main` функции `check_fuel` и `calculate_distance` являются неидентифицированными (`U`)
nm после свзяывания:
```main
0000000000004030 B __bss_start
00000000000012ce T calculate_distance
00000000000012e8 T check_fuel
                 w __cxa_finalize@GLIBC_2.2.5
0000000000004020 D __data_start
0000000000004020 W data_start
0000000000004028 D __dso_handle
0000000000003de0 d _DYNAMIC
0000000000004030 D _edata
0000000000004038 B _end
0000000000001318 T _fini
0000000000003fe8 d _GLOBAL_OFFSET_TABLE_
                 w __gmon_start__
0000000000002130 r __GNU_EH_FRAME_HDR
0000000000001000 T _init
0000000000002000 R _IO_stdin_used
                 U __isoc99_scanf@GLIBC_2.7
                 w _ITM_deregisterTMCloneTable
                 w _ITM_registerTMCloneTable
                 U __libc_start_main@GLIBC_2.34
0000000000001169 T main
                 U printf@GLIBC_2.2.5
                 U puts@GLIBC_2.2.5
                 U __stack_chk_fail@GLIBC_2.4
0000000000001070 T _start
0000000000004030 D __TMC_END__
```
Все фукнции являются объявленными (`T`)
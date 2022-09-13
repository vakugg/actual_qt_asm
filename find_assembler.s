.text
.globl  _get_call_adress
_get_call_address:
        mov (%esp), %eax
	ret

.globl  _learn_new_letter
_learn_new_letter:
        pop %edx                  /*Получение точки возврата для перезаписи кода и смещения адреса возврата в стеке на адрес возврата из функции-дерева*/
        mov %eax, %ecx
        /*jmp _learn_new_letter_sub*/ /*Переход на функцию формирования кода дерева*/

.globl  _find_assem
_find_assem:
WORD_0:
	mov 4(%esp),%edx
MET_0:
	movzbl 0(%edx),%eax
	cmpb $0x61,%al
	jne RET_0
	jmp MET_1
RET_0:
	mov $-1,%eax
	ret
MET_1:
	movzbl 1(%edx),%eax
	cmpb $0x61,%al
	jne RET_1
	jmp MET_2
RET_1:
	mov $-1,%eax
	ret
MET_2:
	movzbl 2(%edx),%eax
	cmpb $0x0,%al
	jne RET_2
	ret
RET_2:
	mov $-1,%eax
	ret

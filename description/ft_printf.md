# FT PRINTF

<img src="../img/ft_printf.png"/>
<a href="https://github.com/kungbi/42seoul_storage/tree/master/ft_printf"
   style="color: #000; font-size: 20px">
   🔗Repository Link🔗
</a>

## 프로젝트 설명

putnbr이나 putstr로는 한계가 있다. printf를 만들어보는 프로젝트 입니다. 다만 실제 printf처럼 buffer를 사용하지 않습니다. variadic arguments의 사용 방법에 대해 알 수 있습니다.

## 제약 조건

외부 함수는 malloc, free, write, va_start, va_arg, va_copy, va_end 만 사용가능 합니다.

## Mandatory part

Prototype: `int ft_printf(const char *, ...›`

- libc의 printf를 구현한다.
- 실제 printf처럼 버퍼관리를 하지 않는다.
- 다음의 서식 지정자를 구현한다. `cspdiuxx%`

---

<img src="../img/ft_printf_paco.png">

---

<br/>
<img src="../img/ft_printf_score.png">

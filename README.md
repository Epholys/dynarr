# dynarr
Dynamic and Generic Array using C macros

## Use Case
Everytime an array with an unknown size is necessary.

## Use
Declare a array with DYNARR_DECLARE(), initialize it with
DYNARR_INIT(), fill it with DYNARR_PUSH(), remove last-inserted
elements with DYNARR_POP() and don't forget to deallocate the memory with
DYNARR_DESTRUCT().

As a C-struct, you can (and will) access all of its attribute: elements,
size, capacity and sizeof_type.

## Example
~~~c
int main()
{
 size_t i;

 DYNARR_DECLARE(int, my_stack);

 DYNARR_INIT(int, &my_stack);

 for(i=0; i<10; ++i) {
     DYNARR_PUSH(&my_stack, i);
 }

 DYNARR_POP(&my_stack);
 
 for(i=0; i<my_stack.size; ++i) {
     printf("%d", my_stack.elements[i]);
 }

 DYNARR_DESTRUCT(&my_stack)
}
~~~


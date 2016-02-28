/******************************************************************************
 *
 * dynarr - Dynamic and Generic Array using C macros
 * Copyright 2015 Thomas Munoz (epholys@gmail.com)
 *
 * dynarr is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * dynarr is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with dynarr. If not, see <http://www.gnu.org/licenses/>.
 * 
 *****************************************************************************/

/*! \file
 *  \brief Macro definitions for very simple typed stack of dynamic size.
 *
 * # Use Case
 * Everytime an array with an unknown size is necessary.
 * 
 * # Use
 * Declare a array with DYNARR_DECLARE(), initialize it with
 * DYNARR_INIT(), fill it with DYNARR_PUSH(), remove last-inserted
 * elements with DYNARR_POP() and don't forget to deallocate the memory with
 * DYNARR_DESTRUCT().
 *
 * As a C-struct, you can (and will) access all of its attribute: elements,
 * size, capacity and sizeof_type.
 *
 * # Example
 * ~~~c
 * int main()
 * {
 *  size_t i;
 *
 *  DYNARR_DECLARE(int, my_stack);
 *
 *  DYNARR_INIT(int, &my_stack);
 *
 *  for(i=0; i<10; ++i) {
 *      DYNARR_PUSH(&my_stack, i);
 *  }
 *
 *  DYNARR_POP(&my_stack);
 *  
 *  for(i=0; i<my_stack.size; ++i) {
 *      printf("%d", my_stack.elements[i]);
 *  }
 *
 *  DYNARR_DESTRUCT(&my_stack)
 * }
 * ~~~
 */

#ifndef DYNARR_H
#define DYNARR_H

#include<stdlib.h>
#include<stddef.h>

#ifndef DYNARR_INITIAL_CAPACITY
/*! \brief Initial capacity of the array. Can be overriden. */
#  define DYNARR_INITIAL_CAPACITY (1)
#endif
#ifndef DYNARR_CAPACITY_COEFF
/*! \brief Growth factor of the capacity. Can be overriden. */
#  define DYNARR_CAPACITY_COEFF   (2)
#endif

/*! \brief Declare a dynamic ta ble.
 *
 *  The dynamic array is declared as an anonymous struct with an object of this
 *  type, so it can be defined by itself, inside a struct or a function.
 *
 *  \param[in] Type The type of the array's elements.
 *  \param[in] name The name of the array.
 */
#define DYNARR_DECLARE(Type, name)  \
    struct                          \
    {                               \
        Type * elements;            \
        size_t sizeof_type;         \
        size_t size;                \
        size_t capacity;            \
    } name

/*! \brief Construct a dynamic array by initializing all of its attributes.
 *
 *  \param[in] Type The type of the array's elements. The behavior is undefined if
 *  Type isn't the correct type.
 *  \param[out] ptr  A pointer to the array. The behavior is undefined if ptr isn't a
 *  valid pointer.
 *
 *  \warning Undefined behavior in some cases.
 */

#define DYNARR_INIT(Type, ptr)                                         \
    (ptr)->sizeof_type = sizeof(Type);                                 \
    (ptr)->size = 0;                                                   \
    (ptr)->capacity = DYNARR_INITIAL_CAPACITY;                         \
    (ptr)->elements = malloc(((ptr)->capacity)*((ptr)->sizeof_type));  \

/*! \brief Destruct a dynamic array, freeing the memory.
 *
 *  \param[out] ptr A pointer to the array. The behavior is undefined if ptr isn't a
 *  valid pointer.
 *
 *  \warning Undefined behavior in some cases.
 */
#define DYNARR_DESTRUCT(ptr)  \
    free((ptr)->elements);    \
    (ptr)->elements = NULL    \

/*! \brief Copy an element at the end of the array.
 *
 * Reallocs the memory if necessary.  
 *
 *  \param[in,out] ptr  A pointer to the array. The behavior is undefined if ptr isn't a
 *  valid pointer.
 *  \param[in]     elem The element to copy into the end of the array.
 *
 *  \warning Undefined behavior in some cases.
 *  \warning Can invalidate pointers.
 */
#define DYNARR_PUSH(ptr,elem)                         \
	do {                                              \
        while((ptr)->size + 1 >= (ptr)->capacity){    \
            (ptr)->capacity *= DYNARR_CAPACITY_COEFF; \
            (ptr)->elements = realloc((ptr)->elements, (ptr)->capacity * (ptr)->sizeof_type); \
        }                                             \
        ++((ptr)->size);                              \
        (ptr)->elements[(ptr)->size - 1] = (elem);    \
	} while(0)

/*! \brief Move the end-of-array indicator to virtually remove the last
 *  element.
 *
 * Do nothing if the array is already empty.
 *  
 *  \param[in,out] ptr  A pointer to the array. The behavior is undefined if ptr isn't a
 *  valid pointer.
 *
 *  \warning Undefined behavior in some cases.
 */
#define DYNARR_POP(ptr)                 \
    if((ptr)->size != 0) --((ptr)->size)

/*! \brief Move the end-of-array indicator to virtually remove all the
 *  elements.
 *  
 *  \param[out] ptr  A pointer to the array. The behavior is undefined if ptr isn't a
 *  valid pointer.
 *
 *  \warning Undefined behavior in some cases.
 */
#define DYNARR_CLEAR(ptr) \
    ((ptr)->size = 0)


#endif /* DYNARR_H */

/******************************************************************************
 *
 * dynarr - Dynamic and Generic Array using C macros
 * Copyright 2016 Thomas Munoz (epholys@gmail.com)
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
 *  \brief Definition of unit tests for dynarr.
 */
#include"dynarr_test.h"

#define BCUT_DYNARR_SIZE (8)
static const int fibbo8[BCUT_DYNARR_SIZE] = {0, 1, 1, 2, 3, 5, 8, 13};

BCUT_TEST(dynarr_push)
{
    size_t index;

    DYNARR_DECLARE(int, array);
    DYNARR_CONSTRUCT(int, &array);
    for(index=0; index<BCUT_DYNARR_SIZE; ++index)
    {
        DYNARR_PUSH(&array, fibbo8[index]);
    }

    BCUT_ASSERT(array.size == BCUT_DYNARR_SIZE);
    for(index=0; index<BCUT_DYNARR_SIZE; ++index)
    {
        BCUT_ASSERT(array.elements[index] == fibbo8[index]);
    }

    DYNARR_DESTRUCT(&array);
}

BCUT_TEST(dynarr_pop)
{
    const size_t n_removed = 3;
    size_t suite_size = BCUT_DYNARR_SIZE;
    size_t index;

    DYNARR_DECLARE(int, array);
    DYNARR_CONSTRUCT(int, &array);
    for(index=0; index<suite_size; ++index)
    {
        DYNARR_PUSH(&array, fibbo8[index]);
    }
    for(index=0; index<n_removed; ++index)
    {
        DYNARR_POP(&array);
        suite_size--;
    }

    BCUT_ASSERT(array.size == suite_size);
    for(index=0; index<suite_size; ++index)
    {
        BCUT_ASSERT(array.elements[index] == fibbo8[index]);
    }
   
    DYNARR_DESTRUCT(&array);
}

BCUT_TEST(dynarr_clear)
{
    size_t index;

    DYNARR_DECLARE(int, array);
    DYNARR_CONSTRUCT(int, &array);
    for(index=0; index<BCUT_DYNARR_SIZE; ++index)
    {
        DYNARR_PUSH(&array, fibbo8[index]);
    }

    DYNARR_CLEAR(&array);
    BCUT_ASSERT(array.size == 0);
    
    DYNARR_DESTRUCT(&array);
}

/*
 * This file is part of Meson Starter Project.
 *
 * This is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License Version 3 as published by
 * the Free Software Foundation.
 *
 * Meson Starter Project is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 */

#include "lib1.hpp"

namespace library1
{

/**
 * @brief Returns an answer
 *
 * @return int
 */
int answer() { return 42; }

/**
 * @brief Function to test if static analysis works
 *
 * @return int*
 */
int *static_analysis_test()
{
    int evil{666};
    return &evil;
}

} // namespace library1
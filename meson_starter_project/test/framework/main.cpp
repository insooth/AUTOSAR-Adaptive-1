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

#include "TestSession.hpp"

int main(int argc, char *argv[])
{
    return test::framework::TestSession().run(argc, argv);
}
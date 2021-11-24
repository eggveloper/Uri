#ifndef URI_HPP
#define URI_HPP

/**
 * @file Uri.cpp
 * 
 * This module contains the implementation of the Uri::Uri class.
 * 
 * © 2021 by Callum Ali
 */

#include <Uri/Uri.hpp>

namespace Uri {
    /**
     * Contains the private properties of a Uri instance.
     */
    struct Uri::Impl {

    };

    Uri::~Uri() = default;

    Uri::Uri() : impl_(new Impl) {}
}

#endif /* URI_HPP */
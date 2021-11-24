/**
 * @file Uri.hpp
 * 
 * This module declares the Uri::Uri class.
 * 
 * © 2021 by Callum Ali
 */

#include <memory>

namespace Uri {
    /**
     * This class represents an Uniform Resource Identifier (URI)
     * as defined in RFC 3986 (https://tools.ietf.org/html/rfc3986).
     */
    class Uri {
    public:
        ~Uri();
        Uri(const Uri&) = delete;
        Uri(Uri&&) = delete;
        Uri& operator=(const Uri&) = delete;
        Uri& operator=(Uri&&) = delete;
    public:
        /**
         * Default Constructor
         */
        Uri();
    private:
        struct Impl;

        std::unique_ptr<struct Impl> impl_;
    };
}
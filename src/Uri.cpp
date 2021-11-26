#ifndef URI_HPP
#define URI_HPP

/**
 * @file Uri.cpp
 * 
 * This module contains the implementation of the Uri::Uri class.
 * 
 * © 2021 by Callum Ali
 */

#include <string>
#include <vector>
#include <Uri/Uri.hpp>

namespace Uri {
    /**
     * Contains the private properties of a Uri instance.
     */
    struct Uri::Impl {
        /**
         * @brief The character or character sequence
         * that should be interpreted as a path delimiter.
         */
        std::string pathDelimiter = "/";

        /**
         * @brief The "scheme" element of the URI.
         */
        std::string scheme;

        /**
         * @brief The "host" element of the URI.
         */
        std::string host;

        /**
         * @brief The "path" element of the URI
         * as a sequence of steps.
         */
        std::vector<std::string> path;
    };

    Uri::~Uri() = default;

    Uri::Uri() : impl_(new Impl) {}

    void Uri::setPathDelimiter(const std::string& newPathDelimiter) {
        impl_->pathDelimiter = newPathDelimiter;
    }

    bool Uri::parseFromString(const std::string& uriString) {
        // Scheme Parsing //

        const auto schemeEnd = uriString.find(':');
        impl_->scheme = uriString.substr(0, schemeEnd);
        auto rest = uriString.substr(schemeEnd + 1);

        // Host Parsing //

        if (rest.substr(0, 2) == "//") {
            const auto authorityEnd = rest.find(impl_->pathDelimiter, 2);
            impl_->host = rest.substr(2, authorityEnd - 2);
            rest = rest.substr(authorityEnd);
        } else {
            impl_->host.clear();
        }

        // Path Parsing //

        impl_->path.clear();

        if (rest == impl_->pathDelimiter) {
            // Special case of a path that is empty but needs a single
            // empty-string element to indicate that it is absolute.

            impl_->path.push_back("");
        } else if (!rest.empty()) {
            for(;;) {
                auto pathDelimiter = rest.find(impl_->pathDelimiter);

                if (pathDelimiter == std::string::npos) {
                    impl_->path.push_back(rest);
                    break;
                } else {
                    impl_->path.emplace_back(
                        rest.begin(),
                        rest.begin() + pathDelimiter
                    );

                    rest = rest.substr(pathDelimiter + impl_->pathDelimiter.length());
                }
            }
        }

        return true;
    }

    std::string Uri::getScheme() const {
        return impl_->scheme;
    }

    std::string Uri::getHost() const {
        return impl_->host;
    }

    std::vector<std::string> Uri::getPath() const {
        return impl_->path;
    }
}

#endif /* URI_HPP */
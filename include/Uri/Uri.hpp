/**
 * @file Uri.hpp
 * 
 * This module declares the Uri::Uri class.
 * 
 * © 2021 by Callum Ali
 */

#include <memory>
#include <string>
#include <vector>

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

        /**
         * @brief This method sets the character or character sequence
         * that should be interpreted as a path delimiter.
         * 
         * @param[in] newPathDelimiter Character or character sequence
         * that should be interpreted as a path delimiter.
         */
        void setPathDelimiter(const std::string& newPathDelimiter);

        /**
         * @brief This method builds the URI from the elements parsed
         * from the given string rendering of a URI.
         * 
         * @param[in] uriString String rendering of a URI to parse.
         * @return[bool] Indication of whether or not the URI was parsed successfully.
         */
        bool parseFromString(const std::string& uriString);

        /**
         * @brief This method returns the "scheme" element of the URI.
         * 
         * @return The "scheme" element of the URI.
         * @retval "" is returned if there is no "scheme" element in the URI.
         */
        std::string getScheme() const;

        /**
         * @brief This method returns the "host" element of the URI.
         * 
         * @return The "host" element of the URI.
         * @retval "" is returned if there is no "host" element in the URI.
         */
        std::string getHost() const;

        /**
         * @brief This method returns the "path" element of the URI
         * as a sequence of steps.
         * 
         * @note If the first step of the path is an empty string,
         * then the URI has an absolute path.
         * 
         * @return The "path" element of the URI as a sequence of steps.
         * 
         */
        std::vector<std::string> getPath() const;
    private:
        struct Impl;

        std::unique_ptr<struct Impl> impl_;
    };
}
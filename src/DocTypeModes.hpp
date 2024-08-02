#pragma once

namespace TidyHtml5Dotnet
{
    public enum class DocTypeModes
    {
        Html5 = 0, /**< <!DOCTYPE html> */
        Omit,      /**< Omit DOCTYPE altogether */
        Auto,      /**< Keep DOCTYPE in input.  Set version to content */
        Strict,    /**< Convert document to HTML 4 strict content model */
        Loose,     /**< Convert document to HTML 4 transitional content model */
        User       /**< Set DOCTYPE FPI explicitly */
    };
}
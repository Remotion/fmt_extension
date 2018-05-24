#pragma once
#ifndef FMT_RGB_RE_H_
#define FMT_RGB_RE_H_
//=================================================================================================
//  fmt_rgb.h
//  #include "fmt_rgb.h"
//  Created: 05.19.2018
//  Remotion (C) 2018 - All Rights Reserved
//=================================================================================================


namespace fmt {

// rgb is a struct for red, green and blue colors.
struct rgb {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

// https://en.wikipedia.org/wiki/ANSI_escape_code
//-----------------------------------------------------------------------------
void to_esc(uint8_t c, char out[], int offset) {
    out[offset + 0] = static_cast<char>('0' + c / 100);
    out[offset + 1] = static_cast<char>('0' + c / 10 % 10);
    out[offset + 2] = static_cast<char>('0' + c % 10);
}

void vprint_rgb(rgb fd, string_view format, format_args args) {

    char escape_fd[] = "\x1b[38;2;000;000;000m";

    to_esc(fd.r, escape_fd, 7);
    to_esc(fd.g, escape_fd, 11);
    to_esc(fd.b, escape_fd, 15);

    std::fputs(escape_fd, stdout);
    vprint(format, args);
    std::fputs(RESET_COLOR, stdout);
}

//-----------------------------------------------------------------------------
void vprint_rgb(rgb fd, rgb bg, string_view format, format_args args) {

    char escape_fd[] = "\x1b[38;2;000;000;000m"; // foreground color
    char escape_bg[] = "\x1b[48;2;000;000;000m"; // background color

    to_esc(fd.r, escape_fd, 7);
    to_esc(fd.g, escape_fd, 11);
    to_esc(fd.b, escape_fd, 15);

    to_esc(bg.r, escape_bg, 7);
    to_esc(bg.g, escape_bg, 11);
    to_esc(bg.b, escape_bg, 15);

    std::fputs(escape_fd, stdout);
    std::fputs(escape_bg, stdout);
    vprint(format, args);
    std::fputs(RESET_COLOR, stdout);
}

template <typename... Args>
inline void print_rgb(rgb fd, string_view format_str, const Args & ... args) {
    vprint_rgb(fd, format_str, make_format_args(args...));
}

// rgb foreground color
template <typename... Args>
inline void print(rgb fd, string_view format_str, const Args & ... args) {
    vprint_rgb(fd, format_str, make_format_args(args...));
}

// rgb foreground color and background color
template <typename... Args>
inline void print(rgb fd, rgb bg, string_view format_str, const Args & ... args) {
    vprint_rgb(fd, bg, format_str, make_format_args(args...));
}

} // namespace fmt


#endif // FMT_RGB_RE_H_
# Nagato

A near pure-C++ implementation/node addon of the osu! Bancho packet paser built for [amaterasu](https://github.com/kuragarimoe/amaterasu) and other correlated projects.

# Requirements
* A C/C++ compiler, most notably [GCC](https://gcc.gnu.org/)
* Node.js v14 (The Node.js Addon API is known to change for every major version, so the tested version is the preferred version.)

# Technical Standpoint
The disbenefits to having the parser and writer being built in Node.js itself alongside the bancho server software means we have to deal with the intended technical limitations of Node.js itself,

such as:
* JavaScript is single-threaded.
    * Which means that unideally, if an invalid packet can't be read then the entire server is resultingly asynchrously trapped.
* JavaScript can be slow.
* Node.js is notoriously bulky (but fortunately provides us with the support for this project to work.)

Thus forth, the fundamental advantages of creating this project?
* Overall performance boost
* Support for easier multi-threading if needed
* C++ flex
* Easily supported by Node.js itselef

Aren't those some great benefits?

# Building
To be honest, I don't know how to plot out this section so I'll do that later when I'm not the only one working on this lmao
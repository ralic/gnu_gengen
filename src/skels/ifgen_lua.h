/*
 * File automatically generated by
 * gengen 1.4.3rc by Lorenzo Bettini 
 * http://www.gnu.org/software/gengen
 */

#ifndef IFGEN_LUA_GEN_CLASS_H
#define IFGEN_LUA_GEN_CLASS_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;

class ifgen_lua_gen_class
{
 protected:
  string else_body;
  string exp;
  bool skipelse;
  string then_body;

 public:
  ifgen_lua_gen_class() :
    skipelse (false)
  {
  }
  
  ifgen_lua_gen_class(const string &_else_body, const string &_exp, bool _skipelse, const string &_then_body) :
    else_body (_else_body), exp (_exp), skipelse (_skipelse), then_body (_then_body)
  {
  }

  static void
  generate_string(const string &s, ostream &stream, unsigned int indent)
  {
    if (!indent || s.find('\n') == string::npos)
      {
        stream << s;
        return;
      }

    string::size_type pos;
    string::size_type start = 0;
    string ind (indent, ' ');
    while ( (pos=s.find('\n', start)) != string::npos)
      {
        stream << s.substr (start, (pos+1)-start);
        start = pos+1;
        if (start+1 <= s.size ())
          stream << ind;
      }
    if (start+1 <= s.size ())
      stream << s.substr (start);
  }

  void set_else_body(const string &_else_body)
  {
    else_body = _else_body;
  }

  void set_exp(const string &_exp)
  {
    exp = _exp;
  }

  void set_skipelse(bool _skipelse)
  {
    skipelse = _skipelse;
  }

  void set_then_body(const string &_then_body)
  {
    then_body = _then_body;
  }

  void generate_ifgen_lua(ostream &stream, unsigned int indent = 0)
  {
    string indent_str (indent, ' ');
    indent = 0;
  
    stream << "\n";
    stream << indent_str;
    stream << "if (";
    generate_string (exp, stream, indent + indent_str.length ());
    stream << ") then";
    stream << "\n";
    stream << indent_str;
    indent = 2;
    stream << "  ";
    generate_string (then_body, stream, indent + indent_str.length ());
    indent = 0;
    stream << "\n";
    stream << indent_str;
    if (skipelse)
      {
        stream << "end";
      }
    else
      {
        stream << "\n";
        stream << indent_str;
        stream << "else";
        stream << "\n";
        stream << indent_str;
        indent = 2;
        stream << "  ";
        generate_string (else_body, stream, indent + indent_str.length ());
        indent = 0;
        stream << "\n";
        stream << indent_str;
        stream << "end";
      }
    stream << "\n";
    stream << indent_str;
  }
};

#endif // IFGEN_LUA_GEN_CLASS_H

#include "generator.ih"

// The base class header contains some of the member functions hat are
// inherited by the parser class itself. It also defines the tokens to be
// returned by the lexical scanner.

// Writing a base class header may be prevented by the --no-baseclass-header
// option. Otherwise, it's rewritten each time bisonc++ is called to process a
// grammar. Providing the --no-baseclass-header option should not be
// necessary, as all additional functionality should be defined in the
// parser's class header.

void Generator::baseclassHeader() const
{
    if (d_arg.option(0, "no-baseclass-header"))
        return;

    ofstream out;
    ifstream in;

    Msg::open(in,  d_parser.baseclassSkeleton()); 
    Msg::open(out, d_parser.baseclassHeader()); 

    filter(in, out);    
}

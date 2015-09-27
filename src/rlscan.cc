
#line 1 "rlscan.rl"
/*
 *  Copyright 2006-2007 Adrian Thurston <thurston@complang.org>
 *  Copyright 2011 Josef Goettgens
 */

/*  This file is part of Ragel.
 *
 *  Ragel is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 * 
 *  Ragel is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 * 
 *  You should have received a copy of the GNU General Public License
 *  along with Ragel; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA 
 */

#include <iostream>
#include <fstream>
#include <string.h>

#include "ragel.h"
#include "rlscan.h"
#include "inputdata.h"

//#define LOG_TOKENS

using std::ifstream;
using std::istream;
using std::ostream;
using std::cerr;
using std::endl;

enum InlineBlockType
{
	CurlyDelimited,
	SemiTerminated
};

#ifdef _WIN32
#define PATH_SEP '\\'
#else
#define PATH_SEP '/'
#endif

char *newTokdata( int toklen )
{
	char *tokdata = new char[sizeof(TokHead) + toklen + 1];
	return tokdata + sizeof(TokHead);
}

void deleteTokdata( char *tokdata )
{
	if ( tokdata )
		delete[] ( tokdata - sizeof(TokHead) );
}

void linkTokdata( Parser6 *parser, char *tokdata )
{
	TokHead *head = (TokHead*)( tokdata - sizeof(TokHead) );
	head->next = parser->tokHead;
	parser->tokHead = head;
}

void clearTokdata( Parser6 *parser )
{
	while ( parser->tokHead != 0 ) {
		TokHead *next = parser->tokHead->next;
		delete[] (char*)parser->tokHead;
		parser->tokHead = next;
	}
}

/*
 * The Scanner for Importing
 */


#line 151 "rlscan.rl"



#line 91 "rlscan.cc"
static const int inline_token_scan_start = 2;
static const int inline_token_scan_first_final = 2;
static const int inline_token_scan_error = -1;

static const int inline_token_scan_en_main = 2;


#line 154 "rlscan.rl"

void Scanner::flushImport()
{
	int *p = token_data;
	int *pe = token_data + cur_token;
	int *eof = 0;

	
#line 108 "rlscan.cc"
	{
	 tok_cs = inline_token_scan_start;
	 tok_ts = 0;
	 tok_te = 0;
	 tok_act = 0;
	}

#line 116 "rlscan.cc"
	{
	if ( p == pe )
		goto _test_eof;
	switch (  tok_cs )
	{
tr0:
#line 149 "rlscan.rl"
	{{p = (( tok_te))-1;}}
	goto st2;
tr1:
#line 135 "rlscan.rl"
	{ tok_te = p+1;{ 
			int base = tok_ts - token_data;
			int nameOff = 0;
			int litOff = 2;

			directToParser( inclToParser, fileName, line, column, TK_Word, 
					token_strings[base+nameOff], token_lens[base+nameOff] );
			directToParser( inclToParser, fileName, line, column, '=', 0, 0 );
			directToParser( inclToParser, fileName, line, column, TK_Literal,
					token_strings[base+litOff], token_lens[base+litOff] );
			directToParser( inclToParser, fileName, line, column, ';', 0, 0 );
		}}
	goto st2;
tr2:
#line 107 "rlscan.rl"
	{ tok_te = p+1;{ 
			int base = tok_ts - token_data;
			int nameOff = 0;
			int numOff = 2;

			directToParser( inclToParser, fileName, line, column, TK_Word, 
					token_strings[base+nameOff], token_lens[base+nameOff] );
			directToParser( inclToParser, fileName, line, column, '=', 0, 0 );
			directToParser( inclToParser, fileName, line, column, TK_UInt,
					token_strings[base+numOff], token_lens[base+numOff] );
			directToParser( inclToParser, fileName, line, column, ';', 0, 0 );
		}}
	goto st2;
tr3:
#line 121 "rlscan.rl"
	{ tok_te = p+1;{ 
			int base = tok_ts - token_data;
			int nameOff = 1;
			int litOff = 2;

			directToParser( inclToParser, fileName, line, column, TK_Word, 
					token_strings[base+nameOff], token_lens[base+nameOff] );
			directToParser( inclToParser, fileName, line, column, '=', 0, 0 );
			directToParser( inclToParser, fileName, line, column, TK_Literal,
					token_strings[base+litOff], token_lens[base+litOff] );
			directToParser( inclToParser, fileName, line, column, ';', 0, 0 );
		}}
	goto st2;
tr4:
#line 93 "rlscan.rl"
	{ tok_te = p+1;{ 
			int base = tok_ts - token_data;
			int nameOff = 1;
			int numOff = 2;

			directToParser( inclToParser, fileName, line, column, TK_Word, 
					token_strings[base+nameOff], token_lens[base+nameOff] );
			directToParser( inclToParser, fileName, line, column, '=', 0, 0 );
			directToParser( inclToParser, fileName, line, column, TK_UInt,
					token_strings[base+numOff], token_lens[base+numOff] );
			directToParser( inclToParser, fileName, line, column, ';', 0, 0 );
		}}
	goto st2;
tr5:
#line 149 "rlscan.rl"
	{ tok_te = p+1;}
	goto st2;
tr8:
#line 149 "rlscan.rl"
	{ tok_te = p;p--;}
	goto st2;
st2:
#line 1 "NONE"
	{ tok_ts = 0;}
	if ( ++p == pe )
		goto _test_eof2;
case 2:
#line 1 "NONE"
	{ tok_ts = p;}
#line 202 "rlscan.cc"
	switch( (*p) ) {
		case 128: goto tr6;
		case 131: goto tr7;
	}
	goto tr5;
tr6:
#line 1 "NONE"
	{ tok_te = p+1;}
	goto st3;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
#line 216 "rlscan.cc"
	if ( (*p) == 61 )
		goto st0;
	goto tr8;
st0:
	if ( ++p == pe )
		goto _test_eof0;
case 0:
	switch( (*p) ) {
		case 129: goto tr1;
		case 130: goto tr2;
	}
	goto tr0;
tr7:
#line 1 "NONE"
	{ tok_te = p+1;}
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
#line 237 "rlscan.cc"
	if ( (*p) == 128 )
		goto st1;
	goto tr8;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
	switch( (*p) ) {
		case 129: goto tr3;
		case 130: goto tr4;
	}
	goto tr0;
	}
	_test_eof2:  tok_cs = 2; goto _test_eof; 
	_test_eof3:  tok_cs = 3; goto _test_eof; 
	_test_eof0:  tok_cs = 0; goto _test_eof; 
	_test_eof4:  tok_cs = 4; goto _test_eof; 
	_test_eof1:  tok_cs = 1; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch (  tok_cs ) {
	case 3: goto tr8;
	case 0: goto tr0;
	case 4: goto tr8;
	case 1: goto tr0;
	}
	}

	}

#line 165 "rlscan.rl"


	if ( tok_ts == 0 )
		cur_token = 0;
	else {
		cur_token = pe - tok_ts;
		int ts_offset = tok_ts - token_data;
		memmove( token_data, token_data+ts_offset, cur_token*sizeof(token_data[0]) );
		memmove( token_strings, token_strings+ts_offset, cur_token*sizeof(token_strings[0]) );
		memmove( token_lens, token_lens+ts_offset, cur_token*sizeof(token_lens[0]) );
	}
}

void Scanner::directToParser( Parser6 *toParser, const char *tokFileName, int tokLine, 
		int tokColumn, int type, char *tokdata, int toklen )
{
	InputLoc loc;

	#ifdef LOG_TOKENS
	cerr << "scanner:" << tokLine << ":" << tokColumn << 
			": sending token to the parser " << Parser6_lelNames[type];
	cerr << " " << toklen;
	if ( tokdata != 0 )
		cerr << " " << tokdata;
	cerr << endl;
	#endif

	loc.fileName = tokFileName;
	loc.line = tokLine;
	loc.col = tokColumn;

	toParser->token( loc, type, tokdata, toklen );
}

void Scanner::importToken( int token, char *start, char *end )
{
	if ( cur_token == max_tokens )
		flushImport();

	token_data[cur_token] = token;
	if ( start == 0 ) {
		token_strings[cur_token] = 0;
		token_lens[cur_token] = 0;
	}
	else {
		int toklen = end-start;
		token_lens[cur_token] = toklen;
		token_strings[cur_token] = new char[toklen+1];
		memcpy( token_strings[cur_token], start, toklen );
		token_strings[cur_token][toklen] = 0;
	}
	cur_token++;
}

void Scanner::pass()
{
	if ( sectionPass )
		return;

	updateCol();

	/* If no errors and we are at the bottom of the include stack (the
	 * source file listed on the command line) then write out the data. */
	if ( includeDepth == 0 && id.machineSpec == 0 && id.machineName == 0 )
		id.curItem->data.write( ts, te-ts );
}

void Scanner::pass( int token, char *start, char *end )
{
	if ( sectionPass )
		return;

	if ( importMachines )
		importToken( token, start, end );

	pass();
}

/*
 * The scanner for processing sections, includes, imports, etc.
 */


#line 354 "rlscan.cc"
static const int section_parse_start = 10;
static const int section_parse_first_final = 10;
static const int section_parse_error = 0;

static const int section_parse_en_main = 10;


#line 251 "rlscan.rl"


void Scanner::init( )
{
	
#line 368 "rlscan.cc"
	{
	cs = section_parse_start;
	}

#line 256 "rlscan.rl"
}

bool Scanner::active()
{
	if ( ignoreSection )
		return false;

	if ( parser == 0 && ! parserExistsError ) {
		scan_error() << "this specification has no name, nor does any previous"
			" specification" << endl;
		parserExistsError = true;
	}

	if ( parser == 0 )
		return false;

	return true;
}

ostream &Scanner::scan_error()
{
	/* Maintain the error count. */
	gblErrorCount += 1;
	cerr << makeInputLoc( fileName, line, column ) << ": ";
	return cerr;
}

/* An approximate check for duplicate includes. Due to aliasing of files it's
 * possible for duplicates to creep in. */
bool Scanner::duplicateInclude( char *inclFileName, char *inclSectionName )
{
	for ( IncludeHistory::Iter hi = parser->includeHistory; hi.lte(); hi++ ) {
		if ( strcmp( hi->fileName, inclFileName ) == 0 &&
				strcmp( hi->sectionName, inclSectionName ) == 0 )
		{
			return true;
		}
	}
	return false;	
}

void Scanner::updateCol()
{
	char *from = lastnl;
	if ( from == 0 )
		from = ts;
	//cerr << "adding " << te - from << " to column" << endl;
	column += te - from;
	lastnl = 0;
}

void Scanner::handleMachine()
{
	if ( sectionPass ) {
		/* Assign a name to the machine. */
		char *machine = word;

		SectionDictEl *sdEl = id.sectionDict.find( machine );
		if ( sdEl == 0 ) {
			sdEl = new SectionDictEl( machine );
			sdEl->value = new Section( machine );
			id.sectionDict.insert( sdEl );
		}

		section = sdEl->value;
	}
	else {

		/* Assign a name to the machine. */
		char *machine = word;

		if ( !importMachines && inclSectionTarg == 0 ) {
			ignoreSection = false;

			ParserDictEl *pdEl = id.parserDict.find( machine );
			if ( pdEl == 0 ) {
				pdEl = new ParserDictEl( machine );
				pdEl->value = new Parser6( &id, fileName, machine, sectionLoc,
						id.hostLang, id.minimizeLevel, id.minimizeOpt );
				pdEl->value->init();
				id.parserDict.insert( pdEl );
				id.parserList.append( pdEl->value );

				/* Also into the parse data dict. This is the new style. */
				ParseDataDictEl *pddEl = new ParseDataDictEl( machine );
				pddEl->value = pdEl->value->pd;
				id.parseDataDict.insert( pddEl );
				id.parseDataList.append( pddEl->value );
			}

			parser = pdEl->value;
		}
		else if ( !importMachines && strcmp( inclSectionTarg, machine ) == 0 ) {
			/* found include target */
			ignoreSection = false;
			parser = inclToParser;
		}
		else {
			/* ignoring section */
			ignoreSection = true;
			parser = 0;
		}
	}
}

void Scanner::handleInclude()
{
	if ( sectionPass )
		return;

	if ( active() ) {
		char *inclSectionName = word;
		char **includeChecks = 0;

		/* Implement defaults for the input file and section name. */
		if ( inclSectionName == 0 )
			inclSectionName = parser->sectionName;

		if ( lit != 0 )
			includeChecks = makeIncludePathChecks( fileName, lit, lit_len );
		else {
			char *test = new char[strlen(fileName)+1];
			strcpy( test, fileName );

			includeChecks = new char*[2];

			includeChecks[0] = test;
			includeChecks[1] = 0;
		}

		long found = 0;
		ifstream *inFile = tryOpenInclude( includeChecks, found );
		if ( inFile == 0 ) {
			scan_error() << "include: failed to locate file" << endl;
			char **tried = includeChecks;
			while ( *tried != 0 )
				scan_error() << "include: attempted: \"" << *tried++ << '\"' << endl;
		}
		else {
			/* Don't include anything that's already been included. */
			if ( !duplicateInclude( includeChecks[found], inclSectionName ) ) {
				parser->includeHistory.append( IncludeHistoryItem( 
						includeChecks[found], inclSectionName ) );

				Scanner scanner( id, includeChecks[found], *inFile, parser,
						inclSectionName, includeDepth+1, false );
				scanner.do_scan( );
				delete inFile;
			}
		}
	}
}

void Scanner::handleImport()
{
	if ( sectionPass )
		return;

	if ( active() ) {
		char **importChecks = makeIncludePathChecks( fileName, lit, lit_len );

		/* Open the input file for reading. */
		long found = 0;
		ifstream *inFile = tryOpenInclude( importChecks, found );
		if ( inFile == 0 ) {
			scan_error() << "import: could not open import file " <<
					"for reading" << endl;
			char **tried = importChecks;
			while ( *tried != 0 )
				scan_error() << "import: attempted: \"" << *tried++ << '\"' << endl;
		}

		Scanner scanner( id, importChecks[found], *inFile, parser,
				0, includeDepth+1, true );
		scanner.do_scan( );
		scanner.importToken( 0, 0, 0 );
		scanner.flushImport();
		delete inFile;
	}
}


#line 557 "rlscan.rl"


void Scanner::token( int type, char c )
{
	token( type, &c, &c + 1 );
}

void Scanner::token( int type )
{
	token( type, 0, 0 );
}


void Scanner::token( int type, char *start, char *end )
{
	char *tokdata = 0;
	int toklen = 0;
	if ( start != 0 ) {
		toklen = end-start;
		tokdata = newTokdata( toklen + 1 );
		memcpy( tokdata, start, toklen );
		tokdata[toklen] = 0;
	}

	processToken( type, tokdata, toklen );
}

void Scanner::processToken( int type, char *tokdata, int toklen )
{
	int *p, *pe, *eof;

	if ( type < 0 )
		p = pe = eof = 0;
	else {
		p = &type;
		pe = &type + 1;
		eof = 0;
	}

	
#line 597 "rlscan.cc"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
tr2:
#line 452 "rlscan.rl"
	{ handleMachine(); }
	goto st10;
tr6:
#line 453 "rlscan.rl"
	{ handleInclude(); }
	goto st10;
tr10:
#line 454 "rlscan.rl"
	{ handleImport(); }
	goto st10;
tr13:
#line 512 "rlscan.rl"
	{
		if ( sectionPass ) {
		}
		else {
			/* if ( active() && id.machineSpec == 0 && id.machineName == 0 )
			 *	id.curItem->writeArgs.append( 0 ); */
		}
	}
	goto st10;
tr14:
#line 527 "rlscan.rl"
	{
		if ( sectionPass ) {
			deleteTokdata( tokdata );
		}
		else {
			/* Send the token off to the parser. */
			if ( active() ) {
				if ( tokdata != 0 ) {
					linkTokdata( parser, tokdata );
				}

				directToParser( parser, fileName, line, column, type, tokdata, toklen );
			}
			else {
				deleteTokdata( tokdata );
			}
		}
	}
	goto st10;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
#line 651 "rlscan.cc"
	switch( (*p) ) {
		case 196: goto st1;
		case 197: goto st3;
		case 198: goto st6;
		case 199: goto tr18;
	}
	goto tr14;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
	if ( (*p) == 128 )
		goto tr1;
	goto tr0;
tr0:
#line 447 "rlscan.rl"
	{ scan_error() << "bad machine statement" << endl; }
	goto st0;
tr3:
#line 448 "rlscan.rl"
	{ scan_error() << "bad include statement" << endl; }
	goto st0;
tr8:
#line 449 "rlscan.rl"
	{ scan_error() << "bad import statement" << endl; }
	goto st0;
tr11:
#line 450 "rlscan.rl"
	{ scan_error() << "bad write statement" << endl; }
	goto st0;
#line 682 "rlscan.cc"
st0:
cs = 0;
	goto _out;
tr1:
#line 444 "rlscan.rl"
	{ word = tokdata; word_len = toklen; }
	goto st2;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
#line 694 "rlscan.cc"
	if ( (*p) == 59 )
		goto tr2;
	goto tr0;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	switch( (*p) ) {
		case 128: goto tr4;
		case 129: goto tr5;
	}
	goto tr3;
tr4:
#line 443 "rlscan.rl"
	{ word = lit = 0; word_len = lit_len = 0; }
#line 444 "rlscan.rl"
	{ word = tokdata; word_len = toklen; }
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
#line 717 "rlscan.cc"
	switch( (*p) ) {
		case 59: goto tr6;
		case 129: goto tr7;
	}
	goto tr3;
tr5:
#line 443 "rlscan.rl"
	{ word = lit = 0; word_len = lit_len = 0; }
#line 445 "rlscan.rl"
	{ lit = tokdata; lit_len = toklen; }
	goto st5;
tr7:
#line 445 "rlscan.rl"
	{ lit = tokdata; lit_len = toklen; }
	goto st5;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
#line 737 "rlscan.cc"
	if ( (*p) == 59 )
		goto tr6;
	goto tr3;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	if ( (*p) == 129 )
		goto tr9;
	goto tr8;
tr9:
#line 445 "rlscan.rl"
	{ lit = tokdata; lit_len = toklen; }
	goto st7;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
#line 756 "rlscan.cc"
	if ( (*p) == 59 )
		goto tr10;
	goto tr8;
tr18:
#line 474 "rlscan.rl"
	{
		if ( sectionPass ) {
			InputItem *inputItem = new InputItem;
			inputItem->type = InputItem::Write;
			inputItem->loc.fileName = fileName;
			inputItem->loc.line = line;
			inputItem->loc.col = column;
			inputItem->name = section->sectionName;
			inputItem->section = section;

			/* Track the last reference. */
			inputItem->section->lastReference = inputItem;

			id.inputItems.append( inputItem );
		}
		else {
			if ( includeDepth == 0 && active() &&
					id.machineSpec == 0 && id.machineName == 0 )
			{
				id.curItem = id.curItem->next;
				id.curItem->pd = parser->pd;
				id.curItem->parser = parser;
				id.checkLastRef( id.curItem );
			}
		}
	}
	goto st8;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
#line 793 "rlscan.cc"
	if ( (*p) == 128 )
		goto tr12;
	goto tr11;
tr12:
#line 502 "rlscan.rl"
	{
		if ( sectionPass ) {
		}
		else {
			if ( active() && id.machineSpec == 0 && id.machineName == 0 )
				id.curItem->writeArgs.append( strdup(tokdata) );
		}
	}
	goto st9;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
#line 812 "rlscan.cc"
	switch( (*p) ) {
		case 59: goto tr13;
		case 128: goto tr12;
	}
	goto tr11;
	}
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 1: 
	case 2: 
#line 447 "rlscan.rl"
	{ scan_error() << "bad machine statement" << endl; }
	break;
	case 3: 
	case 4: 
	case 5: 
#line 448 "rlscan.rl"
	{ scan_error() << "bad include statement" << endl; }
	break;
	case 6: 
	case 7: 
#line 449 "rlscan.rl"
	{ scan_error() << "bad import statement" << endl; }
	break;
	case 8: 
	case 9: 
#line 450 "rlscan.rl"
	{ scan_error() << "bad write statement" << endl; }
	break;
#line 855 "rlscan.cc"
	}
	}

	_out: {}
	}

#line 599 "rlscan.rl"


	updateCol();

	/* Record the last token for use in controlling the scan of subsequent
	 * tokens. */
	lastToken = type;
}

void Scanner::startSection( )
{
	parserExistsError = false;

	sectionLoc.fileName = fileName;
	sectionLoc.line = line;
	sectionLoc.col = column;
}

void Scanner::endSection( )
{
	/* Execute the eof actions for the section parser. */
	processToken( -1, 0, 0 );

	if ( sectionPass ) {
		InputItem *inputItem = new InputItem;
		inputItem->type = InputItem::EndSection;
		inputItem->loc.fileName = fileName;
		inputItem->loc.line = line;
		inputItem->loc.col = column;
		id.inputItems.append( inputItem );
		if ( section != 0 ) {
			inputItem->section = section;
			section->lastReference = inputItem;
		}

		if ( includeDepth == 0 ) {
			if ( id.machineSpec == 0 && id.machineName == 0 ) {
				/* The end section may include a newline on the end, so
				 * we use the last line, which will count the newline. */
				InputItem *inputItem = new InputItem;
				inputItem->type = InputItem::HostData;
				inputItem->loc.fileName = fileName;
				inputItem->loc.line = line;
				inputItem->loc.col = column;
				id.inputItems.append( inputItem );
			}
		}
	}
	else {
		/* Close off the section with the parser. */
		if ( includeDepth == 0 && active() ) {
			InputLoc loc;
			loc.fileName = fileName;
			loc.line = line;
			loc.col = column;

			parser->token( loc, TK_EndSection, 0, 0 );

			id.curItem = id.curItem->next;

			if ( parser != 0 ) {
				id.curItem->pd = parser->pd;
				id.curItem->parser = parser;
			}

			id.checkLastRef( id.curItem );
		}

		if ( includeDepth == 0 ) {
			if ( id.machineSpec == 0 && id.machineName == 0 ) {
				id.curItem = id.curItem->next;
				id.checkLastRef( id.curItem );
			}
		}
	}
}

bool isAbsolutePath( const char *path )
{
#ifdef _WIN32
	return isalpha( path[0] ) && path[1] == ':' && path[2] == '\\';
#else
	return path[0] == '/';
#endif
}

char **Scanner::makeIncludePathChecks( const char *thisFileName, 
		const char *fileName, int fnlen )
{
	char **checks = 0;
	long nextCheck = 0;
	long length = 0;
	bool caseInsensitive = false;
	char *data = prepareLitString( InputLoc(), fileName, fnlen, 
			length, caseInsensitive );

	/* Absolute path? */
	if ( isAbsolutePath( data ) ) {
		checks = new char*[2];
		checks[nextCheck++] = data;
	}
	else {
		checks = new char*[2 + id.includePaths.length()];

		/* Search from the the location of the current file. */
		const char *lastSlash = strrchr( thisFileName, PATH_SEP );
		if ( lastSlash == 0 )
			checks[nextCheck++] = data;
		else {
			long givenPathLen = (lastSlash - thisFileName) + 1;
			long checklen = givenPathLen + length;
			char *check = new char[checklen+1];
			memcpy( check, thisFileName, givenPathLen );
			memcpy( check+givenPathLen, data, length );
			check[checklen] = 0;
			checks[nextCheck++] = check;
		}

		/* Search from the include paths given on the command line. */
		for ( ArgsVector::Iter incp = id.includePaths; incp.lte(); incp++ ) {
			long pathLen = strlen( *incp );
			long checkLen = pathLen + 1 + length;
			char *check = new char[checkLen+1];
			memcpy( check, *incp, pathLen );
			check[pathLen] = PATH_SEP;
			memcpy( check+pathLen+1, data, length );
			check[checkLen] = 0;
			checks[nextCheck++] = check;
		}
	}

	checks[nextCheck] = 0;
	return checks;
}

ifstream *Scanner::tryOpenInclude( char **pathChecks, long &found )
{
	char **check = pathChecks;
	ifstream *inFile = new ifstream;
	
	while ( *check != 0 ) {
		inFile->open( *check );
		if ( inFile->is_open() ) {
			found = check - pathChecks;
			return inFile;
		}

		/* 
		 * 03/26/2011 jg:
		 * Don't rely on sloppy runtime behaviour: reset the state of the stream explicitly.
		 * If inFile->open() fails, which happens when include dirs are tested, the fail bit
		 * is set by the runtime library. Currently the VS runtime library opens new files,
		 * but when it comes to reading it refuses to work.
		 */
		inFile->clear();

		check += 1;
	}

	found = -1;
	delete inFile;
	return 0;
}


#line 1195 "rlscan.rl"



#line 1032 "rlscan.cc"
static const int rlscan_start = 36;
static const int rlscan_first_final = 36;
static const int rlscan_error = 0;

static const int rlscan_en_inline_code = 50;
static const int rlscan_en_or_literal = 103;
static const int rlscan_en_ragel_re_literal = 105;
static const int rlscan_en_write_statement = 109;
static const int rlscan_en_parser_def = 112;
static const int rlscan_en_main = 36;


#line 1198 "rlscan.rl"

void Scanner::do_scan()
{
	int bufsize = 8;
	char *buf = new char[bufsize];
	int cs, act, have = 0;
	int top;

	/* The stack is two deep, one level for going into ragel defs from the main
	 * machines which process outside code, and another for going into or literals
	 * from either a ragel spec, or a regular expression. */
	int stack[2];
	int curly_count = 0;
	bool execute = true;
	bool singleLineSpec = false;
	InlineBlockType inlineBlockType = CurlyDelimited;

	line = 1;
	column = 1;
	lastnl = 0;

	/* Init the section parser and the character scanner. */
	init();
	
#line 1070 "rlscan.cc"
	{
	cs = rlscan_start;
	top = 0;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 1222 "rlscan.rl"

	/* Set up the start state. FIXME: After 5.20 is released the nocs write
	 * init option should be used, the main machine eliminated and this statement moved
	 * above the write init. */
	cs = rlscan_en_main;
	
	while ( execute ) {
		char *p = buf + have;
		int space = bufsize - have;

		if ( space == 0 ) {
			/* We filled up the buffer trying to scan a token. Grow it. */
			bufsize = bufsize * 2;
			char *newbuf = new char[bufsize];

			/* Recompute p and space. */
			p = newbuf + have;
			space = bufsize - have;

			/* Patch up pointers possibly in use. */
			if ( ts != 0 )
				ts = newbuf + ( ts - buf );
			te = newbuf + ( te - buf );

			/* Copy the new buffer in. */
			memcpy( newbuf, buf, have );
			delete[] buf;
			buf = newbuf;
		}

		input.read( p, space );
		int len = input.gcount();
		char *pe = p + len;

		/* If we see eof then append the eof var. */
		char *eof = 0;
	 	if ( len == 0 ) {
			eof = pe;
			execute = false;
		}

		
#line 1122 "rlscan.cc"
	{
	if ( p == pe )
		goto _test_eof;
	goto _resume;

_again:
	switch ( cs ) {
		case 36: goto st36;
		case 37: goto st37;
		case 38: goto st38;
		case 1: goto st1;
		case 2: goto st2;
		case 39: goto st39;
		case 40: goto st40;
		case 41: goto st41;
		case 3: goto st3;
		case 4: goto st4;
		case 42: goto st42;
		case 5: goto st5;
		case 6: goto st6;
		case 7: goto st7;
		case 43: goto st43;
		case 44: goto st44;
		case 45: goto st45;
		case 46: goto st46;
		case 47: goto st47;
		case 48: goto st48;
		case 49: goto st49;
		case 50: goto st50;
		case 51: goto st51;
		case 52: goto st52;
		case 8: goto st8;
		case 9: goto st9;
		case 53: goto st53;
		case 54: goto st54;
		case 55: goto st55;
		case 10: goto st10;
		case 11: goto st11;
		case 56: goto st56;
		case 12: goto st12;
		case 13: goto st13;
		case 14: goto st14;
		case 57: goto st57;
		case 58: goto st58;
		case 15: goto st15;
		case 59: goto st59;
		case 60: goto st60;
		case 61: goto st61;
		case 62: goto st62;
		case 63: goto st63;
		case 64: goto st64;
		case 65: goto st65;
		case 66: goto st66;
		case 67: goto st67;
		case 68: goto st68;
		case 69: goto st69;
		case 70: goto st70;
		case 71: goto st71;
		case 72: goto st72;
		case 73: goto st73;
		case 74: goto st74;
		case 75: goto st75;
		case 76: goto st76;
		case 77: goto st77;
		case 78: goto st78;
		case 79: goto st79;
		case 80: goto st80;
		case 81: goto st81;
		case 82: goto st82;
		case 83: goto st83;
		case 84: goto st84;
		case 85: goto st85;
		case 86: goto st86;
		case 87: goto st87;
		case 88: goto st88;
		case 89: goto st89;
		case 90: goto st90;
		case 91: goto st91;
		case 92: goto st92;
		case 93: goto st93;
		case 94: goto st94;
		case 95: goto st95;
		case 96: goto st96;
		case 97: goto st97;
		case 98: goto st98;
		case 99: goto st99;
		case 100: goto st100;
		case 101: goto st101;
		case 102: goto st102;
		case 103: goto st103;
		case 104: goto st104;
		case 105: goto st105;
		case 106: goto st106;
		case 107: goto st107;
		case 108: goto st108;
		case 109: goto st109;
		case 0: goto st0;
		case 110: goto st110;
		case 111: goto st111;
		case 112: goto st112;
		case 113: goto st113;
		case 114: goto st114;
		case 16: goto st16;
		case 115: goto st115;
		case 17: goto st17;
		case 116: goto st116;
		case 18: goto st18;
		case 117: goto st117;
		case 118: goto st118;
		case 119: goto st119;
		case 19: goto st19;
		case 20: goto st20;
		case 120: goto st120;
		case 121: goto st121;
		case 122: goto st122;
		case 123: goto st123;
		case 124: goto st124;
		case 21: goto st21;
		case 125: goto st125;
		case 126: goto st126;
		case 22: goto st22;
		case 127: goto st127;
		case 128: goto st128;
		case 129: goto st129;
		case 23: goto st23;
		case 24: goto st24;
		case 25: goto st25;
		case 26: goto st26;
		case 27: goto st27;
		case 28: goto st28;
		case 29: goto st29;
		case 30: goto st30;
		case 31: goto st31;
		case 32: goto st32;
		case 33: goto st33;
		case 34: goto st34;
		case 130: goto st130;
		case 131: goto st131;
		case 132: goto st132;
		case 133: goto st133;
		case 134: goto st134;
		case 135: goto st135;
		case 136: goto st136;
		case 137: goto st137;
		case 138: goto st138;
		case 139: goto st139;
		case 140: goto st140;
		case 141: goto st141;
		case 142: goto st142;
		case 143: goto st143;
		case 144: goto st144;
		case 145: goto st145;
		case 146: goto st146;
		case 147: goto st147;
		case 148: goto st148;
		case 149: goto st149;
		case 150: goto st150;
		case 151: goto st151;
		case 152: goto st152;
		case 153: goto st153;
		case 154: goto st154;
		case 155: goto st155;
		case 156: goto st156;
		case 157: goto st157;
		case 158: goto st158;
		case 159: goto st159;
		case 160: goto st160;
		case 161: goto st161;
		case 162: goto st162;
		case 163: goto st163;
		case 164: goto st164;
		case 165: goto st165;
		case 166: goto st166;
		case 167: goto st167;
		case 168: goto st168;
		case 169: goto st169;
		case 170: goto st170;
		case 171: goto st171;
		case 172: goto st172;
		case 173: goto st173;
		case 174: goto st174;
		case 175: goto st175;
		case 176: goto st176;
		case 177: goto st177;
		case 178: goto st178;
		case 179: goto st179;
		case 180: goto st180;
		case 181: goto st181;
		case 182: goto st182;
		case 183: goto st183;
		case 184: goto st184;
		case 185: goto st185;
		case 186: goto st186;
		case 187: goto st187;
		case 188: goto st188;
		case 189: goto st189;
		case 190: goto st190;
		case 191: goto st191;
		case 192: goto st192;
		case 193: goto st193;
		case 194: goto st194;
		case 195: goto st195;
		case 196: goto st196;
		case 197: goto st197;
		case 198: goto st198;
		case 199: goto st199;
		case 200: goto st200;
		case 201: goto st201;
		case 202: goto st202;
		case 203: goto st203;
		case 204: goto st204;
		case 205: goto st205;
		case 206: goto st206;
		case 207: goto st207;
		case 208: goto st208;
		case 209: goto st209;
		case 210: goto st210;
		case 211: goto st211;
		case 212: goto st212;
		case 213: goto st213;
		case 214: goto st214;
		case 215: goto st215;
		case 216: goto st216;
		case 217: goto st217;
		case 218: goto st218;
		case 219: goto st219;
		case 220: goto st220;
		case 221: goto st221;
		case 222: goto st222;
		case 223: goto st223;
		case 224: goto st224;
		case 225: goto st225;
		case 226: goto st226;
		case 227: goto st227;
		case 228: goto st228;
		case 229: goto st229;
		case 230: goto st230;
		case 231: goto st231;
		case 232: goto st232;
		case 233: goto st233;
		case 234: goto st234;
		case 35: goto st35;
	default: break;
	}

	if ( ++p == pe )
		goto _test_eof;
_resume:
	switch ( cs )
	{
tr0:
#line 1193 "rlscan.rl"
	{{p = ((te))-1;}{ pass( *ts, 0, 0 ); }}
	goto st36;
tr3:
#line 1177 "rlscan.rl"
	{te = p+1;{ pass( IMP_Literal, ts, te ); }}
	goto st36;
tr11:
#line 1176 "rlscan.rl"
	{te = p+1;{ pass(); }}
	goto st36;
tr13:
#line 769 "rlscan.rl"
	{ 
		lastnl = p; 
		column = 0;
		line++;
	}
#line 1176 "rlscan.rl"
	{te = p+1;{ pass(); }}
	goto st36;
tr59:
#line 1193 "rlscan.rl"
	{te = p+1;{ pass( *ts, 0, 0 ); }}
	goto st36;
tr60:
#line 1192 "rlscan.rl"
	{te = p+1;}
	goto st36;
tr70:
#line 1191 "rlscan.rl"
	{te = p;p--;{ pass(); }}
	goto st36;
tr71:
#line 1193 "rlscan.rl"
	{te = p;p--;{ pass( *ts, 0, 0 ); }}
	goto st36;
tr73:
#line 1185 "rlscan.rl"
	{te = p;p--;{ 
			updateCol();
			singleLineSpec = true;
			startSection();
			{stack[top++] = 36; goto st112;}
		}}
	goto st36;
tr74:
#line 1179 "rlscan.rl"
	{te = p+1;{ 
			updateCol();
			singleLineSpec = false;
			startSection();
			{stack[top++] = 36; goto st112;}
		}}
	goto st36;
tr75:
#line 1175 "rlscan.rl"
	{te = p;p--;{ pass( IMP_UInt, ts, te ); }}
	goto st36;
tr76:
#line 1 "NONE"
	{	switch( act ) {
	case 154:
	{{p = ((te))-1;} pass( IMP_Define, 0, 0 ); }
	break;
	case 155:
	{{p = ((te))-1;} pass( IMP_Word, ts, te ); }
	break;
	}
	}
	goto st36;
tr77:
#line 1174 "rlscan.rl"
	{te = p;p--;{ pass( IMP_Word, ts, te ); }}
	goto st36;
st36:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof36;
case 36:
#line 1 "NONE"
	{ts = p;}
#line 1457 "rlscan.cc"
	switch( (*p) ) {
		case 0: goto tr60;
		case 9: goto st37;
		case 10: goto tr62;
		case 32: goto st37;
		case 34: goto tr63;
		case 37: goto st39;
		case 39: goto tr65;
		case 47: goto tr66;
		case 95: goto tr68;
		case 100: goto st45;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st43;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr68;
	} else
		goto tr68;
	goto tr59;
tr62:
#line 769 "rlscan.rl"
	{ 
		lastnl = p; 
		column = 0;
		line++;
	}
	goto st37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
#line 1491 "rlscan.cc"
	switch( (*p) ) {
		case 9: goto st37;
		case 10: goto tr62;
		case 32: goto st37;
	}
	goto tr70;
tr63:
#line 1 "NONE"
	{te = p+1;}
	goto st38;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
#line 1506 "rlscan.cc"
	switch( (*p) ) {
		case 10: goto tr2;
		case 34: goto tr3;
		case 92: goto st2;
	}
	goto st1;
tr2:
#line 769 "rlscan.rl"
	{ 
		lastnl = p; 
		column = 0;
		line++;
	}
	goto st1;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
#line 1525 "rlscan.cc"
	switch( (*p) ) {
		case 10: goto tr2;
		case 34: goto tr3;
		case 92: goto st2;
	}
	goto st1;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( (*p) == 10 )
		goto tr2;
	goto st1;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
	if ( (*p) == 37 )
		goto st40;
	goto tr71;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
	if ( (*p) == 123 )
		goto tr74;
	goto tr73;
tr65:
#line 1 "NONE"
	{te = p+1;}
	goto st41;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
#line 1561 "rlscan.cc"
	switch( (*p) ) {
		case 10: goto tr6;
		case 39: goto tr3;
		case 92: goto st4;
	}
	goto st3;
tr6:
#line 769 "rlscan.rl"
	{ 
		lastnl = p; 
		column = 0;
		line++;
	}
	goto st3;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
#line 1580 "rlscan.cc"
	switch( (*p) ) {
		case 10: goto tr6;
		case 39: goto tr3;
		case 92: goto st4;
	}
	goto st3;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
	if ( (*p) == 10 )
		goto tr6;
	goto st3;
tr66:
#line 1 "NONE"
	{te = p+1;}
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
#line 1602 "rlscan.cc"
	switch( (*p) ) {
		case 42: goto st5;
		case 47: goto st7;
	}
	goto tr71;
tr9:
#line 769 "rlscan.rl"
	{ 
		lastnl = p; 
		column = 0;
		line++;
	}
	goto st5;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
#line 1620 "rlscan.cc"
	switch( (*p) ) {
		case 10: goto tr9;
		case 42: goto st6;
	}
	goto st5;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	switch( (*p) ) {
		case 10: goto tr9;
		case 42: goto st6;
		case 47: goto tr11;
	}
	goto st5;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	if ( (*p) == 10 )
		goto tr13;
	goto st7;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st43;
	goto tr75;
tr68:
#line 1 "NONE"
	{te = p+1;}
#line 1174 "rlscan.rl"
	{act = 155;}
	goto st44;
tr82:
#line 1 "NONE"
	{te = p+1;}
#line 1173 "rlscan.rl"
	{act = 154;}
	goto st44;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
#line 1666 "rlscan.cc"
	if ( (*p) == 95 )
		goto tr68;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr68;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr68;
	} else
		goto tr68;
	goto tr76;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
	switch( (*p) ) {
		case 95: goto tr68;
		case 101: goto st46;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr68;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr68;
	} else
		goto tr68;
	goto tr77;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
	switch( (*p) ) {
		case 95: goto tr68;
		case 102: goto st47;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr68;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr68;
	} else
		goto tr68;
	goto tr77;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
	switch( (*p) ) {
		case 95: goto tr68;
		case 105: goto st48;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr68;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr68;
	} else
		goto tr68;
	goto tr77;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
	switch( (*p) ) {
		case 95: goto tr68;
		case 110: goto st49;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr68;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr68;
	} else
		goto tr68;
	goto tr77;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	switch( (*p) ) {
		case 95: goto tr68;
		case 101: goto tr82;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr68;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr68;
	} else
		goto tr68;
	goto tr77;
tr14:
#line 920 "rlscan.rl"
	{{p = ((te))-1;}{ token( IL_Symbol, ts, te ); }}
	goto st50;
tr17:
#line 857 "rlscan.rl"
	{te = p+1;{ token( IL_Literal, ts, te ); }}
	goto st50;
tr25:
#line 864 "rlscan.rl"
	{te = p+1;{ token( IL_Comment, ts, te ); }}
	goto st50;
tr27:
#line 769 "rlscan.rl"
	{ 
		lastnl = p; 
		column = 0;
		line++;
	}
#line 864 "rlscan.rl"
	{te = p+1;{ token( IL_Comment, ts, te ); }}
	goto st50;
tr28:
#line 853 "rlscan.rl"
	{{p = ((te))-1;}{ token( TK_UInt, ts, te ); }}
	goto st50;
tr83:
#line 920 "rlscan.rl"
	{te = p+1;{ token( IL_Symbol, ts, te ); }}
	goto st50;
tr84:
#line 915 "rlscan.rl"
	{te = p+1;{
			scan_error() << "unterminated code block" << endl;
		}}
	goto st50;
tr90:
#line 895 "rlscan.rl"
	{te = p+1;{ token( *ts, ts, te ); }}
	goto st50;
tr91:
#line 890 "rlscan.rl"
	{te = p+1;{ 
			whitespaceOn = true;
			token( *ts, ts, te );
		}}
	goto st50;
tr96:
#line 874 "rlscan.rl"
	{te = p+1;{
			whitespaceOn = true;
			token( *ts, ts, te );
			if ( inlineBlockType == SemiTerminated )
				{cs = stack[--top];goto _again;}
		}}
	goto st50;
tr99:
#line 897 "rlscan.rl"
	{te = p+1;{ 
			token( IL_Symbol, ts, te );
			curly_count += 1; 
		}}
	goto st50;
tr100:
#line 902 "rlscan.rl"
	{te = p+1;{ 
			if ( --curly_count == 0 && inlineBlockType == CurlyDelimited ) {
				/* Inline code block ends. */
				token( '}' );
				{cs = stack[--top];goto _again;}
			}
			else {
				/* Either a semi terminated inline block or only the closing
				 * brace of some inner scope, not the block's closing brace. */
				token( IL_Symbol, ts, te );
			}
		}}
	goto st50;
tr101:
#line 859 "rlscan.rl"
	{te = p;p--;{ 
			if ( whitespaceOn ) 
				token( IL_WhiteSpace, ts, te );
		}}
	goto st50;
tr102:
#line 920 "rlscan.rl"
	{te = p;p--;{ token( IL_Symbol, ts, te ); }}
	goto st50;
tr104:
#line 881 "rlscan.rl"
	{te = p;p--;{
			if ( parser != 0 && parser->parseSubstitutions )
				token( TK_SubstRef, ts+1, te );
			else {
				token( IL_Symbol, ts, ts+1 );
				{p = (( ts+1))-1;}
			}
		}}
	goto st50;
tr105:
#line 853 "rlscan.rl"
	{te = p;p--;{ token( TK_UInt, ts, te ); }}
	goto st50;
tr107:
#line 854 "rlscan.rl"
	{te = p;p--;{ token( TK_Hex, ts, te ); }}
	goto st50;
tr108:
#line 866 "rlscan.rl"
	{te = p+1;{ token( TK_NameSep, ts, te ); }}
	goto st50;
tr109:
#line 1 "NONE"
	{	switch( act ) {
	case 1:
	{{p = ((te))-1;} token( KW_PChar ); }
	break;
	case 3:
	{{p = ((te))-1;} token( KW_CurState ); }
	break;
	case 4:
	{{p = ((te))-1;} token( KW_TargState ); }
	break;
	case 5:
	{{p = ((te))-1;} 
			whitespaceOn = false; 
			token( KW_Entry );
		}
	break;
	case 6:
	{{p = ((te))-1;} 
			whitespaceOn = false; 
			token( KW_Hold );
		}
	break;
	case 7:
	{{p = ((te))-1;} token( KW_Exec, 0, 0 ); }
	break;
	case 8:
	{{p = ((te))-1;} 
			whitespaceOn = false; 
			token( KW_Goto );
		}
	break;
	case 9:
	{{p = ((te))-1;} 
			whitespaceOn = false; 
			token( KW_Next );
		}
	break;
	case 10:
	{{p = ((te))-1;} 
			whitespaceOn = false; 
			token( KW_Call );
		}
	break;
	case 11:
	{{p = ((te))-1;} 
			whitespaceOn = false; 
			token( KW_Ret );
		}
	break;
	case 12:
	{{p = ((te))-1;} 
			whitespaceOn = false; 
			token( KW_Break );
		}
	break;
	case 13:
	{{p = ((te))-1;} 
			whitespaceOn = false; 
			token( KW_Ncall );
		}
	break;
	case 14:
	{{p = ((te))-1;} 
			whitespaceOn = false; 
			token( KW_Nret );
		}
	break;
	case 15:
	{{p = ((te))-1;} 
			whitespaceOn = false; 
			token( KW_Nbreak );
		}
	break;
	case 16:
	{{p = ((te))-1;} token( TK_Word, ts, te ); }
	break;
	}
	}
	goto st50;
tr110:
#line 851 "rlscan.rl"
	{te = p;p--;{ token( TK_Word, ts, te ); }}
	goto st50;
tr124:
#line 804 "rlscan.rl"
	{te = p;p--;{ token( KW_Char ); }}
	goto st50;
st50:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof50;
case 50:
#line 1 "NONE"
	{ts = p;}
#line 1972 "rlscan.cc"
	switch( (*p) ) {
		case 0: goto tr84;
		case 9: goto st51;
		case 10: goto tr86;
		case 32: goto st51;
		case 34: goto tr87;
		case 36: goto st53;
		case 39: goto tr89;
		case 40: goto tr90;
		case 44: goto tr90;
		case 47: goto tr92;
		case 48: goto tr93;
		case 58: goto st60;
		case 59: goto tr96;
		case 95: goto tr97;
		case 102: goto st62;
		case 123: goto tr99;
		case 125: goto tr100;
	}
	if ( (*p) < 49 ) {
		if ( 41 <= (*p) && (*p) <= 42 )
			goto tr91;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr97;
		} else if ( (*p) >= 65 )
			goto tr97;
	} else
		goto st58;
	goto tr83;
tr86:
#line 769 "rlscan.rl"
	{ 
		lastnl = p; 
		column = 0;
		line++;
	}
	goto st51;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
#line 2016 "rlscan.cc"
	switch( (*p) ) {
		case 9: goto st51;
		case 10: goto tr86;
		case 32: goto st51;
	}
	goto tr101;
tr87:
#line 1 "NONE"
	{te = p+1;}
	goto st52;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
#line 2031 "rlscan.cc"
	switch( (*p) ) {
		case 10: goto tr16;
		case 34: goto tr17;
		case 92: goto st9;
	}
	goto st8;
tr16:
#line 769 "rlscan.rl"
	{ 
		lastnl = p; 
		column = 0;
		line++;
	}
	goto st8;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
#line 2050 "rlscan.cc"
	switch( (*p) ) {
		case 10: goto tr16;
		case 34: goto tr17;
		case 92: goto st9;
	}
	goto st8;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
	if ( (*p) == 10 )
		goto tr16;
	goto st8;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
	if ( (*p) == 95 )
		goto st54;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st54;
	} else if ( (*p) >= 65 )
		goto st54;
	goto tr102;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	if ( (*p) == 95 )
		goto st54;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st54;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st54;
	} else
		goto st54;
	goto tr104;
tr89:
#line 1 "NONE"
	{te = p+1;}
	goto st55;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
#line 2099 "rlscan.cc"
	switch( (*p) ) {
		case 10: goto tr20;
		case 39: goto tr17;
		case 92: goto st11;
	}
	goto st10;
tr20:
#line 769 "rlscan.rl"
	{ 
		lastnl = p; 
		column = 0;
		line++;
	}
	goto st10;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
#line 2118 "rlscan.cc"
	switch( (*p) ) {
		case 10: goto tr20;
		case 39: goto tr17;
		case 92: goto st11;
	}
	goto st10;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
	if ( (*p) == 10 )
		goto tr20;
	goto st10;
tr92:
#line 1 "NONE"
	{te = p+1;}
	goto st56;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
#line 2140 "rlscan.cc"
	switch( (*p) ) {
		case 42: goto st12;
		case 47: goto st14;
	}
	goto tr102;
tr23:
#line 769 "rlscan.rl"
	{ 
		lastnl = p; 
		column = 0;
		line++;
	}
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
#line 2158 "rlscan.cc"
	switch( (*p) ) {
		case 10: goto tr23;
		case 42: goto st13;
	}
	goto st12;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	switch( (*p) ) {
		case 10: goto tr23;
		case 42: goto st13;
		case 47: goto tr25;
	}
	goto st12;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
	if ( (*p) == 10 )
		goto tr27;
	goto st14;
tr93:
#line 1 "NONE"
	{te = p+1;}
	goto st57;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
#line 2189 "rlscan.cc"
	if ( (*p) == 120 )
		goto st15;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st58;
	goto tr105;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st58;
	goto tr105;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st59;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st59;
	} else
		goto st59;
	goto tr28;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st59;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st59;
	} else
		goto st59;
	goto tr107;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	if ( (*p) == 58 )
		goto tr108;
	goto tr102;
tr97:
#line 1 "NONE"
	{te = p+1;}
#line 851 "rlscan.rl"
	{act = 16;}
	goto st61;
tr123:
#line 1 "NONE"
	{te = p+1;}
#line 834 "rlscan.rl"
	{act = 12;}
	goto st61;
tr128:
#line 1 "NONE"
	{te = p+1;}
#line 826 "rlscan.rl"
	{act = 10;}
	goto st61;
tr130:
#line 1 "NONE"
	{te = p+1;}
#line 805 "rlscan.rl"
	{act = 3;}
	goto st61;
tr135:
#line 1 "NONE"
	{te = p+1;}
#line 807 "rlscan.rl"
	{act = 5;}
	goto st61;
tr137:
#line 1 "NONE"
	{te = p+1;}
#line 817 "rlscan.rl"
	{act = 7;}
	goto st61;
tr140:
#line 1 "NONE"
	{te = p+1;}
#line 818 "rlscan.rl"
	{act = 8;}
	goto st61;
tr143:
#line 1 "NONE"
	{te = p+1;}
#line 813 "rlscan.rl"
	{act = 6;}
	goto st61;
tr151:
#line 1 "NONE"
	{te = p+1;}
#line 846 "rlscan.rl"
	{act = 15;}
	goto st61;
tr154:
#line 1 "NONE"
	{te = p+1;}
#line 838 "rlscan.rl"
	{act = 13;}
	goto st61;
tr156:
#line 1 "NONE"
	{te = p+1;}
#line 822 "rlscan.rl"
	{act = 9;}
	goto st61;
tr158:
#line 1 "NONE"
	{te = p+1;}
#line 842 "rlscan.rl"
	{act = 14;}
	goto st61;
tr159:
#line 1 "NONE"
	{te = p+1;}
#line 803 "rlscan.rl"
	{act = 1;}
	goto st61;
tr161:
#line 1 "NONE"
	{te = p+1;}
#line 830 "rlscan.rl"
	{act = 11;}
	goto st61;
tr165:
#line 1 "NONE"
	{te = p+1;}
#line 806 "rlscan.rl"
	{act = 4;}
	goto st61;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
#line 2329 "rlscan.cc"
	if ( (*p) == 95 )
		goto tr97;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr109;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	switch( (*p) ) {
		case 95: goto tr97;
		case 98: goto st63;
		case 99: goto st67;
		case 101: goto st72;
		case 103: goto st78;
		case 104: goto st81;
		case 110: goto st84;
		case 112: goto st96;
		case 114: goto st97;
		case 116: goto st99;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
	switch( (*p) ) {
		case 95: goto tr97;
		case 114: goto st64;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
	switch( (*p) ) {
		case 95: goto tr97;
		case 101: goto st65;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	switch( (*p) ) {
		case 95: goto tr97;
		case 97: goto st66;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
	switch( (*p) ) {
		case 95: goto tr97;
		case 107: goto tr123;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
	switch( (*p) ) {
		case 95: goto tr97;
		case 97: goto st68;
		case 117: goto st70;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr124;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	switch( (*p) ) {
		case 95: goto tr97;
		case 108: goto st69;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
	switch( (*p) ) {
		case 95: goto tr97;
		case 108: goto tr128;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	switch( (*p) ) {
		case 95: goto tr97;
		case 114: goto st71;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
	switch( (*p) ) {
		case 95: goto tr97;
		case 115: goto tr130;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	switch( (*p) ) {
		case 95: goto tr97;
		case 110: goto st73;
		case 120: goto st76;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	switch( (*p) ) {
		case 95: goto tr97;
		case 116: goto st74;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	switch( (*p) ) {
		case 95: goto tr97;
		case 114: goto st75;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
	switch( (*p) ) {
		case 95: goto tr97;
		case 121: goto tr135;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
	switch( (*p) ) {
		case 95: goto tr97;
		case 101: goto st77;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	switch( (*p) ) {
		case 95: goto tr97;
		case 99: goto tr137;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
	switch( (*p) ) {
		case 95: goto tr97;
		case 111: goto st79;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	switch( (*p) ) {
		case 95: goto tr97;
		case 116: goto st80;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
	switch( (*p) ) {
		case 95: goto tr97;
		case 111: goto tr140;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
	switch( (*p) ) {
		case 95: goto tr97;
		case 111: goto st82;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
	switch( (*p) ) {
		case 95: goto tr97;
		case 108: goto st83;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
	switch( (*p) ) {
		case 95: goto tr97;
		case 100: goto tr143;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
	switch( (*p) ) {
		case 95: goto tr97;
		case 98: goto st85;
		case 99: goto st89;
		case 101: goto st92;
		case 114: goto st94;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
	switch( (*p) ) {
		case 95: goto tr97;
		case 114: goto st86;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	switch( (*p) ) {
		case 95: goto tr97;
		case 101: goto st87;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	switch( (*p) ) {
		case 95: goto tr97;
		case 97: goto st88;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
	switch( (*p) ) {
		case 95: goto tr97;
		case 107: goto tr151;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	switch( (*p) ) {
		case 95: goto tr97;
		case 97: goto st90;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
	switch( (*p) ) {
		case 95: goto tr97;
		case 108: goto st91;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	switch( (*p) ) {
		case 95: goto tr97;
		case 108: goto tr154;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	switch( (*p) ) {
		case 95: goto tr97;
		case 120: goto st93;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
	switch( (*p) ) {
		case 95: goto tr97;
		case 116: goto tr156;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	switch( (*p) ) {
		case 95: goto tr97;
		case 101: goto st95;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
	switch( (*p) ) {
		case 95: goto tr97;
		case 116: goto tr158;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
	switch( (*p) ) {
		case 95: goto tr97;
		case 99: goto tr159;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
	switch( (*p) ) {
		case 95: goto tr97;
		case 101: goto st98;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
	switch( (*p) ) {
		case 95: goto tr97;
		case 116: goto tr161;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
	switch( (*p) ) {
		case 95: goto tr97;
		case 97: goto st100;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
	switch( (*p) ) {
		case 95: goto tr97;
		case 114: goto st101;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
	switch( (*p) ) {
		case 95: goto tr97;
		case 103: goto st102;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
	switch( (*p) ) {
		case 95: goto tr97;
		case 115: goto tr165;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr97;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr97;
	} else
		goto tr97;
	goto tr110;
tr166:
#line 947 "rlscan.rl"
	{te = p+1;{ token( RE_Char, ts, te ); }}
	goto st103;
tr167:
#line 942 "rlscan.rl"
	{te = p+1;{
			scan_error() << "unterminated OR literal" << endl;
		}}
	goto st103;
tr168:
#line 937 "rlscan.rl"
	{te = p+1;{ token( RE_Dash, 0, 0 ); }}
	goto st103;
tr170:
#line 940 "rlscan.rl"
	{te = p+1;{ token( RE_SqClose ); {cs = stack[--top];goto _again;} }}
	goto st103;
tr171:
#line 947 "rlscan.rl"
	{te = p;p--;{ token( RE_Char, ts, te ); }}
	goto st103;
tr172:
#line 934 "rlscan.rl"
	{te = p+1;{ token( RE_Char, ts+1, te ); }}
	goto st103;
tr173:
#line 933 "rlscan.rl"
	{te = p+1;{ updateCol(); }}
	goto st103;
tr174:
#line 925 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\0' ); }}
	goto st103;
tr175:
#line 926 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\a' ); }}
	goto st103;
tr176:
#line 927 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\b' ); }}
	goto st103;
tr177:
#line 931 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\f' ); }}
	goto st103;
tr178:
#line 929 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\n' ); }}
	goto st103;
tr179:
#line 932 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\r' ); }}
	goto st103;
tr180:
#line 928 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\t' ); }}
	goto st103;
tr181:
#line 930 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\v' ); }}
	goto st103;
st103:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof103;
case 103:
#line 1 "NONE"
	{ts = p;}
#line 3121 "rlscan.cc"
	switch( (*p) ) {
		case 0: goto tr167;
		case 45: goto tr168;
		case 92: goto st104;
		case 93: goto tr170;
	}
	goto tr166;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
	switch( (*p) ) {
		case 10: goto tr173;
		case 48: goto tr174;
		case 97: goto tr175;
		case 98: goto tr176;
		case 102: goto tr177;
		case 110: goto tr178;
		case 114: goto tr179;
		case 116: goto tr180;
		case 118: goto tr181;
	}
	goto tr172;
tr182:
#line 982 "rlscan.rl"
	{te = p+1;{ token( RE_Char, ts, te ); }}
	goto st105;
tr183:
#line 977 "rlscan.rl"
	{te = p+1;{
			scan_error() << "unterminated regular expression" << endl;
		}}
	goto st105;
tr184:
#line 972 "rlscan.rl"
	{te = p+1;{ token( RE_Star ); }}
	goto st105;
tr185:
#line 971 "rlscan.rl"
	{te = p+1;{ token( RE_Dot ); }}
	goto st105;
tr189:
#line 965 "rlscan.rl"
	{te = p;p--;{ 
			token( RE_Slash, ts, te ); 
			{goto st112;}
		}}
	goto st105;
tr190:
#line 965 "rlscan.rl"
	{te = p+1;{ 
			token( RE_Slash, ts, te ); 
			{goto st112;}
		}}
	goto st105;
tr191:
#line 974 "rlscan.rl"
	{te = p;p--;{ token( RE_SqOpen ); {stack[top++] = 105; goto st103;} }}
	goto st105;
tr192:
#line 975 "rlscan.rl"
	{te = p+1;{ token( RE_SqOpenNeg ); {stack[top++] = 105; goto st103;} }}
	goto st105;
tr193:
#line 982 "rlscan.rl"
	{te = p;p--;{ token( RE_Char, ts, te ); }}
	goto st105;
tr194:
#line 962 "rlscan.rl"
	{te = p+1;{ token( RE_Char, ts+1, te ); }}
	goto st105;
tr195:
#line 961 "rlscan.rl"
	{te = p+1;{ updateCol(); }}
	goto st105;
tr196:
#line 953 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\0' ); }}
	goto st105;
tr197:
#line 954 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\a' ); }}
	goto st105;
tr198:
#line 955 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\b' ); }}
	goto st105;
tr199:
#line 959 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\f' ); }}
	goto st105;
tr200:
#line 957 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\n' ); }}
	goto st105;
tr201:
#line 960 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\r' ); }}
	goto st105;
tr202:
#line 956 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\t' ); }}
	goto st105;
tr203:
#line 958 "rlscan.rl"
	{te = p+1;{ token( RE_Char, '\v' ); }}
	goto st105;
st105:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof105;
case 105:
#line 1 "NONE"
	{ts = p;}
#line 3237 "rlscan.cc"
	switch( (*p) ) {
		case 0: goto tr183;
		case 42: goto tr184;
		case 46: goto tr185;
		case 47: goto st106;
		case 91: goto st107;
		case 92: goto st108;
	}
	goto tr182;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
	if ( (*p) == 105 )
		goto tr190;
	goto tr189;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
	if ( (*p) == 94 )
		goto tr192;
	goto tr191;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
	switch( (*p) ) {
		case 10: goto tr195;
		case 48: goto tr196;
		case 97: goto tr197;
		case 98: goto tr198;
		case 102: goto tr199;
		case 110: goto tr200;
		case 114: goto tr201;
		case 116: goto tr202;
		case 118: goto tr203;
	}
	goto tr194;
tr204:
#line 991 "rlscan.rl"
	{te = p+1;{
			scan_error() << "unterminated write statement" << endl;
		}}
	goto st109;
tr207:
#line 989 "rlscan.rl"
	{te = p+1;{ token( ';' ); {goto st112;} }}
	goto st109;
tr209:
#line 988 "rlscan.rl"
	{te = p;p--;{ updateCol(); }}
	goto st109;
tr210:
#line 987 "rlscan.rl"
	{te = p;p--;{ token( TK_Word, ts, te ); }}
	goto st109;
st109:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof109;
case 109:
#line 1 "NONE"
	{ts = p;}
#line 3303 "rlscan.cc"
	switch( (*p) ) {
		case 0: goto tr204;
		case 32: goto st110;
		case 59: goto tr207;
		case 95: goto st111;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 10 )
			goto st110;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st111;
	} else
		goto st111;
	goto st0;
st0:
cs = 0;
	goto _out;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
	if ( (*p) == 32 )
		goto st110;
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st110;
	goto tr209;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
	if ( (*p) == 95 )
		goto st111;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st111;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st111;
	} else
		goto st111;
	goto tr210;
tr30:
#line 1168 "rlscan.rl"
	{{p = ((te))-1;}{ token( *ts ); }}
	goto st112;
tr36:
#line 769 "rlscan.rl"
	{ 
		lastnl = p; 
		column = 0;
		line++;
	}
#line 1059 "rlscan.rl"
	{te = p+1;{ updateCol(); }}
	goto st112;
tr40:
#line 1112 "rlscan.rl"
	{{p = ((te))-1;}{ token( TK_DotDot ); }}
	goto st112;
tr41:
#line 1113 "rlscan.rl"
	{te = p+1;{ token( TK_DotDotIndep ); }}
	goto st112;
tr42:
#line 1046 "rlscan.rl"
	{{p = ((te))-1;}{ token( TK_UInt, ts, te ); }}
	goto st112;
tr47:
#line 1126 "rlscan.rl"
	{te = p+1;{ token( TK_ColonCondOpen ); }}
	goto st112;
tr51:
#line 1124 "rlscan.rl"
	{te = p+1;{ token( TK_ColonNfaOpen ); }}
	goto st112;
tr53:
#line 1125 "rlscan.rl"
	{te = p+1;{ token( TK_ColonNfaOpen ); }}
	goto st112;
tr57:
#line 1127 "rlscan.rl"
	{te = p+1;{ token( TK_ColonNoMaxOpen ); }}
	goto st112;
tr58:
#line 1136 "rlscan.rl"
	{te = p+1;{ 
			updateCol();
			endSection();
			{cs = stack[--top];goto _again;}
		}}
	goto st112;
tr211:
#line 1168 "rlscan.rl"
	{te = p+1;{ token( *ts ); }}
	goto st112;
tr212:
#line 1164 "rlscan.rl"
	{te = p+1;{
			scan_error() << "unterminated ragel section" << endl;
		}}
	goto st112;
tr214:
#line 769 "rlscan.rl"
	{ 
		lastnl = p; 
		column = 0;
		line++;
	}
#line 1145 "rlscan.rl"
	{te = p+1;{
			updateCol();
			if ( singleLineSpec ) {
				endSection();
				{cs = stack[--top];goto _again;}
			}
		}}
	goto st112;
tr224:
#line 1056 "rlscan.rl"
	{te = p+1;{ token( RE_Slash ); {goto st105;} }}
	goto st112;
tr247:
#line 1153 "rlscan.rl"
	{te = p+1;{ 
			if ( lastToken == KW_Export || lastToken == KW_Entry )
				token( '{' );
			else {
				token( '{' );
				curly_count = 1; 
				inlineBlockType = CurlyDelimited;
				{stack[top++] = 112; goto st50;}
			}
		}}
	goto st112;
tr250:
#line 1142 "rlscan.rl"
	{te = p;p--;{ updateCol(); }}
	goto st112;
tr251:
#line 1168 "rlscan.rl"
	{te = p;p--;{ token( *ts ); }}
	goto st112;
tr252:
#line 1051 "rlscan.rl"
	{te = p;p--;{ token( TK_Literal, ts, te ); }}
	goto st112;
tr253:
#line 1051 "rlscan.rl"
	{te = p+1;{ token( TK_Literal, ts, te ); }}
	goto st112;
tr254:
#line 1090 "rlscan.rl"
	{te = p+1;{ token( TK_AllGblError ); }}
	goto st112;
tr255:
#line 1074 "rlscan.rl"
	{te = p+1;{ token( TK_AllFromState ); }}
	goto st112;
tr256:
#line 1082 "rlscan.rl"
	{te = p+1;{ token( TK_AllEOF ); }}
	goto st112;
tr257:
#line 1109 "rlscan.rl"
	{te = p+1;{ token( TK_AllCond ); }}
	goto st112;
tr258:
#line 1098 "rlscan.rl"
	{te = p+1;{ token( TK_AllLocalError ); }}
	goto st112;
tr259:
#line 1066 "rlscan.rl"
	{te = p+1;{ token( TK_AllToState ); }}
	goto st112;
tr260:
#line 1091 "rlscan.rl"
	{te = p+1;{ token( TK_FinalGblError ); }}
	goto st112;
tr261:
#line 1075 "rlscan.rl"
	{te = p+1;{ token( TK_FinalFromState ); }}
	goto st112;
tr262:
#line 1083 "rlscan.rl"
	{te = p+1;{ token( TK_FinalEOF ); }}
	goto st112;
tr263:
#line 1110 "rlscan.rl"
	{te = p+1;{ token( TK_LeavingCond ); }}
	goto st112;
tr264:
#line 1099 "rlscan.rl"
	{te = p+1;{ token( TK_FinalLocalError ); }}
	goto st112;
tr265:
#line 1067 "rlscan.rl"
	{te = p+1;{ token( TK_FinalToState ); }}
	goto st112;
tr266:
#line 1128 "rlscan.rl"
	{te = p+1;{ token( TK_CloseColon ); }}
	goto st112;
tr267:
#line 1115 "rlscan.rl"
	{te = p+1;{ token( TK_StarStar ); }}
	goto st112;
tr268:
#line 1116 "rlscan.rl"
	{te = p+1;{ token( TK_DashDash ); }}
	goto st112;
tr269:
#line 1117 "rlscan.rl"
	{te = p+1;{ token( TK_Arrow ); }}
	goto st112;
tr271:
#line 1112 "rlscan.rl"
	{te = p;p--;{ token( TK_DotDot ); }}
	goto st112;
tr273:
#line 1046 "rlscan.rl"
	{te = p;p--;{ token( TK_UInt, ts, te ); }}
	goto st112;
tr275:
#line 1047 "rlscan.rl"
	{te = p;p--;{ token( TK_Hex, ts, te ); }}
	goto st112;
tr276:
#line 1134 "rlscan.rl"
	{te = p+1;{ token( TK_NameSep, ts, te ); }}
	goto st112;
tr277:
#line 1061 "rlscan.rl"
	{te = p+1;{ token( TK_ColonEquals ); }}
	goto st112;
tr281:
#line 1120 "rlscan.rl"
	{te = p;p--;{ token( TK_ColonGt ); }}
	goto st112;
tr282:
#line 1121 "rlscan.rl"
	{te = p+1;{ token( TK_ColonGtGt ); }}
	goto st112;
tr283:
#line 1092 "rlscan.rl"
	{te = p+1;{ token( TK_NotStartGblError ); }}
	goto st112;
tr284:
#line 1076 "rlscan.rl"
	{te = p+1;{ token( TK_NotStartFromState ); }}
	goto st112;
tr285:
#line 1084 "rlscan.rl"
	{te = p+1;{ token( TK_NotStartEOF ); }}
	goto st112;
tr286:
#line 1122 "rlscan.rl"
	{te = p+1;{ token( TK_LtColon ); }}
	goto st112;
tr288:
#line 1100 "rlscan.rl"
	{te = p+1;{ token( TK_NotStartLocalError ); }}
	goto st112;
tr289:
#line 1068 "rlscan.rl"
	{te = p+1;{ token( TK_NotStartToState ); }}
	goto st112;
tr290:
#line 1105 "rlscan.rl"
	{te = p;p--;{ token( TK_Middle ); }}
	goto st112;
tr291:
#line 1094 "rlscan.rl"
	{te = p+1;{ token( TK_MiddleGblError ); }}
	goto st112;
tr292:
#line 1078 "rlscan.rl"
	{te = p+1;{ token( TK_MiddleFromState ); }}
	goto st112;
tr293:
#line 1086 "rlscan.rl"
	{te = p+1;{ token( TK_MiddleEOF ); }}
	goto st112;
tr294:
#line 1102 "rlscan.rl"
	{te = p+1;{ token( TK_MiddleLocalError ); }}
	goto st112;
tr295:
#line 1070 "rlscan.rl"
	{te = p+1;{ token( TK_MiddleToState ); }}
	goto st112;
tr296:
#line 1118 "rlscan.rl"
	{te = p+1;{ token( TK_DoubleArrow ); }}
	goto st112;
tr297:
#line 1089 "rlscan.rl"
	{te = p+1;{ token( TK_StartGblError ); }}
	goto st112;
tr298:
#line 1073 "rlscan.rl"
	{te = p+1;{ token( TK_StartFromState ); }}
	goto st112;
tr299:
#line 1081 "rlscan.rl"
	{te = p+1;{ token( TK_StartEOF ); }}
	goto st112;
tr300:
#line 1108 "rlscan.rl"
	{te = p+1;{ token( TK_StartCond ); }}
	goto st112;
tr301:
#line 1097 "rlscan.rl"
	{te = p+1;{ token( TK_StartLocalError ); }}
	goto st112;
tr302:
#line 1065 "rlscan.rl"
	{te = p+1;{ token( TK_StartToState ); }}
	goto st112;
tr303:
#line 1093 "rlscan.rl"
	{te = p+1;{ token( TK_NotFinalGblError ); }}
	goto st112;
tr304:
#line 1077 "rlscan.rl"
	{te = p+1;{ token( TK_NotFinalFromState ); }}
	goto st112;
tr305:
#line 1085 "rlscan.rl"
	{te = p+1;{ token( TK_NotFinalEOF ); }}
	goto st112;
tr306:
#line 1101 "rlscan.rl"
	{te = p+1;{ token( TK_NotFinalLocalError ); }}
	goto st112;
tr307:
#line 1069 "rlscan.rl"
	{te = p+1;{ token( TK_NotFinalToState ); }}
	goto st112;
tr308:
#line 1 "NONE"
	{	switch( act ) {
	case 66:
	{{p = ((te))-1;} token( KW_Machine ); }
	break;
	case 67:
	{{p = ((te))-1;} token( KW_Include ); }
	break;
	case 68:
	{{p = ((te))-1;} token( KW_Import ); }
	break;
	case 69:
	{{p = ((te))-1;} 
			token( KW_Write );
			{goto st109;}
		}
	break;
	case 70:
	{{p = ((te))-1;} token( KW_Action ); }
	break;
	case 71:
	{{p = ((te))-1;} token( KW_AlphType ); }
	break;
	case 72:
	{{p = ((te))-1;} token( KW_PrePush ); }
	break;
	case 73:
	{{p = ((te))-1;} token( KW_PostPop ); }
	break;
	case 74:
	{{p = ((te))-1;} token( KW_NfaPrePush ); }
	break;
	case 75:
	{{p = ((te))-1;} token( KW_NfaPostPop ); }
	break;
	case 76:
	{{p = ((te))-1;} 
			token( KW_GetKey );
			inlineBlockType = SemiTerminated;
			{stack[top++] = 112; goto st50;}
		}
	break;
	case 77:
	{{p = ((te))-1;} 
			token( KW_Access );
			inlineBlockType = SemiTerminated;
			{stack[top++] = 112; goto st50;}
		}
	break;
	case 78:
	{{p = ((te))-1;} 
			token( KW_Variable );
			inlineBlockType = SemiTerminated;
			{stack[top++] = 112; goto st50;}
		}
	break;
	case 79:
	{{p = ((te))-1;} token( KW_When ); }
	break;
	case 80:
	{{p = ((te))-1;} token( KW_InWhen ); }
	break;
	case 81:
	{{p = ((te))-1;} token( KW_OutWhen ); }
	break;
	case 82:
	{{p = ((te))-1;} token( KW_Eof ); }
	break;
	case 83:
	{{p = ((te))-1;} token( KW_Err ); }
	break;
	case 84:
	{{p = ((te))-1;} token( KW_Lerr ); }
	break;
	case 85:
	{{p = ((te))-1;} token( KW_To ); }
	break;
	case 86:
	{{p = ((te))-1;} token( KW_From ); }
	break;
	case 87:
	{{p = ((te))-1;} token( KW_Export ); }
	break;
	case 88:
	{{p = ((te))-1;} token( TK_Word, ts, te ); }
	break;
	}
	}
	goto st112;
tr309:
#line 1053 "rlscan.rl"
	{te = p;p--;{ token( RE_SqOpen ); {stack[top++] = 112; goto st103;} }}
	goto st112;
tr310:
#line 1054 "rlscan.rl"
	{te = p+1;{ token( RE_SqOpenNeg ); {stack[top++] = 112; goto st103;} }}
	goto st112;
tr311:
#line 1043 "rlscan.rl"
	{te = p;p--;{ token( TK_Word, ts, te ); }}
	goto st112;
tr417:
#line 1131 "rlscan.rl"
	{te = p+1;{ token( TK_BarStar ); }}
	goto st112;
tr418:
#line 1062 "rlscan.rl"
	{te = p+1;{ token( TK_BarEquals ); }}
	goto st112;
st112:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof112;
case 112:
#line 1 "NONE"
	{ts = p;}
#line 3761 "rlscan.cc"
	switch( (*p) ) {
		case 0: goto tr212;
		case 9: goto st113;
		case 10: goto tr214;
		case 13: goto st113;
		case 32: goto st113;
		case 34: goto tr215;
		case 35: goto tr216;
		case 36: goto st117;
		case 37: goto st118;
		case 39: goto tr219;
		case 41: goto st120;
		case 42: goto st121;
		case 45: goto st122;
		case 46: goto st123;
		case 47: goto tr224;
		case 48: goto tr225;
		case 58: goto tr227;
		case 60: goto st130;
		case 61: goto st132;
		case 62: goto st133;
		case 64: goto st134;
		case 91: goto st136;
		case 95: goto tr232;
		case 97: goto st137;
		case 101: goto st151;
		case 102: goto st158;
		case 103: goto st161;
		case 105: goto st166;
		case 108: goto st179;
		case 109: goto st182;
		case 110: goto st188;
		case 111: goto st202;
		case 112: goto st208;
		case 116: goto st219;
		case 118: goto st220;
		case 119: goto st227;
		case 123: goto tr247;
		case 124: goto st233;
		case 125: goto tr249;
	}
	if ( (*p) < 65 ) {
		if ( 49 <= (*p) && (*p) <= 57 )
			goto st126;
	} else if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr211;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
	switch( (*p) ) {
		case 9: goto st113;
		case 13: goto st113;
		case 32: goto st113;
	}
	goto tr250;
tr215:
#line 1 "NONE"
	{te = p+1;}
	goto st114;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
#line 3830 "rlscan.cc"
	switch( (*p) ) {
		case 10: goto tr32;
		case 34: goto st115;
		case 92: goto st17;
	}
	goto st16;
tr32:
#line 769 "rlscan.rl"
	{ 
		lastnl = p; 
		column = 0;
		line++;
	}
	goto st16;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
#line 3849 "rlscan.cc"
	switch( (*p) ) {
		case 10: goto tr32;
		case 34: goto st115;
		case 92: goto st17;
	}
	goto st16;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
	if ( (*p) == 105 )
		goto tr253;
	goto tr252;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	if ( (*p) == 10 )
		goto tr32;
	goto st16;
tr216:
#line 1 "NONE"
	{te = p+1;}
	goto st116;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
#line 3878 "rlscan.cc"
	if ( (*p) == 10 )
		goto tr36;
	goto st18;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	if ( (*p) == 10 )
		goto tr36;
	goto st18;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
	switch( (*p) ) {
		case 33: goto tr254;
		case 42: goto tr255;
		case 47: goto tr256;
		case 63: goto tr257;
		case 94: goto tr258;
		case 126: goto tr259;
	}
	goto tr251;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
	switch( (*p) ) {
		case 33: goto tr260;
		case 42: goto tr261;
		case 47: goto tr262;
		case 63: goto tr263;
		case 94: goto tr264;
		case 126: goto tr265;
	}
	goto tr251;
tr219:
#line 1 "NONE"
	{te = p+1;}
	goto st119;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
#line 3923 "rlscan.cc"
	switch( (*p) ) {
		case 10: goto tr38;
		case 39: goto st115;
		case 92: goto st20;
	}
	goto st19;
tr38:
#line 769 "rlscan.rl"
	{ 
		lastnl = p; 
		column = 0;
		line++;
	}
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
#line 3942 "rlscan.cc"
	switch( (*p) ) {
		case 10: goto tr38;
		case 39: goto st115;
		case 92: goto st20;
	}
	goto st19;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
	if ( (*p) == 10 )
		goto tr38;
	goto st19;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	if ( (*p) == 58 )
		goto tr266;
	goto tr251;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
	if ( (*p) == 42 )
		goto tr267;
	goto tr251;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
	switch( (*p) ) {
		case 45: goto tr268;
		case 62: goto tr269;
	}
	goto tr251;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
	if ( (*p) == 46 )
		goto tr270;
	goto tr251;
tr270:
#line 1 "NONE"
	{te = p+1;}
	goto st124;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
#line 3994 "rlscan.cc"
	if ( (*p) == 47 )
		goto st21;
	goto tr271;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
	if ( (*p) == 105 )
		goto tr41;
	goto tr40;
tr225:
#line 1 "NONE"
	{te = p+1;}
	goto st125;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
#line 4013 "rlscan.cc"
	if ( (*p) == 120 )
		goto st22;
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st126;
	goto tr273;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st126;
	goto tr273;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st127;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st127;
	} else
		goto st127;
	goto tr42;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st127;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st127;
	} else
		goto st127;
	goto tr275;
tr227:
#line 1 "NONE"
	{te = p+1;}
	goto st128;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
#line 4060 "rlscan.cc"
	switch( (*p) ) {
		case 58: goto tr276;
		case 61: goto tr277;
		case 62: goto st129;
		case 99: goto st23;
		case 110: goto st27;
	}
	goto tr251;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	if ( (*p) == 62 )
		goto tr282;
	goto tr281;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
	if ( (*p) == 111 )
		goto st24;
	goto tr30;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	if ( (*p) == 110 )
		goto st25;
	goto tr30;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
	if ( (*p) == 100 )
		goto st26;
	goto tr30;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	if ( (*p) == 40 )
		goto tr47;
	goto tr30;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
	switch( (*p) ) {
		case 102: goto st28;
		case 111: goto st31;
	}
	goto tr30;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
	if ( (*p) == 97 )
		goto st29;
	goto tr30;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
	switch( (*p) ) {
		case 40: goto tr51;
		case 51: goto st30;
	}
	goto tr30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
	if ( (*p) == 40 )
		goto tr53;
	goto tr30;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
	if ( (*p) == 109 )
		goto st32;
	goto tr30;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	if ( (*p) == 97 )
		goto st33;
	goto tr30;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
	if ( (*p) == 120 )
		goto st34;
	goto tr30;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	if ( (*p) == 40 )
		goto tr57;
	goto tr30;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
	switch( (*p) ) {
		case 33: goto tr283;
		case 42: goto tr284;
		case 47: goto tr285;
		case 58: goto tr286;
		case 62: goto st131;
		case 94: goto tr288;
		case 126: goto tr289;
	}
	goto tr251;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
	switch( (*p) ) {
		case 33: goto tr291;
		case 42: goto tr292;
		case 47: goto tr293;
		case 94: goto tr294;
		case 126: goto tr295;
	}
	goto tr290;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
	if ( (*p) == 62 )
		goto tr296;
	goto tr251;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
	switch( (*p) ) {
		case 33: goto tr297;
		case 42: goto tr298;
		case 47: goto tr299;
		case 63: goto tr300;
		case 94: goto tr301;
		case 126: goto tr302;
	}
	goto tr251;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
	switch( (*p) ) {
		case 33: goto tr303;
		case 42: goto tr304;
		case 47: goto tr305;
		case 94: goto tr306;
		case 126: goto tr307;
	}
	goto tr251;
tr232:
#line 1 "NONE"
	{te = p+1;}
#line 1043 "rlscan.rl"
	{act = 88;}
	goto st135;
tr318:
#line 1 "NONE"
	{te = p+1;}
#line 1022 "rlscan.rl"
	{act = 77;}
	goto st135;
tr321:
#line 1 "NONE"
	{te = p+1;}
#line 1006 "rlscan.rl"
	{act = 70;}
	goto st135;
tr327:
#line 1 "NONE"
	{te = p+1;}
#line 1007 "rlscan.rl"
	{act = 71;}
	goto st135;
tr331:
#line 1 "NONE"
	{te = p+1;}
#line 1035 "rlscan.rl"
	{act = 82;}
	goto st135;
tr332:
#line 1 "NONE"
	{te = p+1;}
#line 1036 "rlscan.rl"
	{act = 83;}
	goto st135;
tr336:
#line 1 "NONE"
	{te = p+1;}
#line 1040 "rlscan.rl"
	{act = 87;}
	goto st135;
tr339:
#line 1 "NONE"
	{te = p+1;}
#line 1039 "rlscan.rl"
	{act = 86;}
	goto st135;
tr344:
#line 1 "NONE"
	{te = p+1;}
#line 1017 "rlscan.rl"
	{act = 76;}
	goto st135;
tr350:
#line 1 "NONE"
	{te = p+1;}
#line 1001 "rlscan.rl"
	{act = 68;}
	goto st135;
tr356:
#line 1 "NONE"
	{te = p+1;}
#line 1000 "rlscan.rl"
	{act = 67;}
	goto st135;
tr359:
#line 1 "NONE"
	{te = p+1;}
#line 1033 "rlscan.rl"
	{act = 80;}
	goto st135;
tr362:
#line 1 "NONE"
	{te = p+1;}
#line 1037 "rlscan.rl"
	{act = 84;}
	goto st135;
tr368:
#line 1 "NONE"
	{te = p+1;}
#line 999 "rlscan.rl"
	{act = 66;}
	goto st135;
tr378:
#line 1 "NONE"
	{te = p+1;}
#line 1012 "rlscan.rl"
	{act = 75;}
	goto st135;
tr383:
#line 1 "NONE"
	{te = p+1;}
#line 1011 "rlscan.rl"
	{act = 74;}
	goto st135;
tr389:
#line 1 "NONE"
	{te = p+1;}
#line 1034 "rlscan.rl"
	{act = 81;}
	goto st135;
tr396:
#line 1 "NONE"
	{te = p+1;}
#line 1009 "rlscan.rl"
	{act = 73;}
	goto st135;
tr401:
#line 1 "NONE"
	{te = p+1;}
#line 1008 "rlscan.rl"
	{act = 72;}
	goto st135;
tr402:
#line 1 "NONE"
	{te = p+1;}
#line 1038 "rlscan.rl"
	{act = 85;}
	goto st135;
tr409:
#line 1 "NONE"
	{te = p+1;}
#line 1027 "rlscan.rl"
	{act = 78;}
	goto st135;
tr413:
#line 1 "NONE"
	{te = p+1;}
#line 1032 "rlscan.rl"
	{act = 79;}
	goto st135;
tr416:
#line 1 "NONE"
	{te = p+1;}
#line 1002 "rlscan.rl"
	{act = 69;}
	goto st135;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
#line 4364 "rlscan.cc"
	if ( (*p) == 95 )
		goto tr232;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr308;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	if ( (*p) == 94 )
		goto tr310;
	goto tr309;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	switch( (*p) ) {
		case 95: goto tr232;
		case 99: goto st138;
		case 108: goto st145;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
	switch( (*p) ) {
		case 95: goto tr232;
		case 99: goto st139;
		case 116: goto st142;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	switch( (*p) ) {
		case 95: goto tr232;
		case 101: goto st140;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
	switch( (*p) ) {
		case 95: goto tr232;
		case 115: goto st141;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
	switch( (*p) ) {
		case 95: goto tr232;
		case 115: goto tr318;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
	switch( (*p) ) {
		case 95: goto tr232;
		case 105: goto st143;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
	switch( (*p) ) {
		case 95: goto tr232;
		case 111: goto st144;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	switch( (*p) ) {
		case 95: goto tr232;
		case 110: goto tr321;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	switch( (*p) ) {
		case 95: goto tr232;
		case 112: goto st146;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	switch( (*p) ) {
		case 95: goto tr232;
		case 104: goto st147;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
	switch( (*p) ) {
		case 95: goto tr232;
		case 116: goto st148;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
	switch( (*p) ) {
		case 95: goto tr232;
		case 121: goto st149;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
	switch( (*p) ) {
		case 95: goto tr232;
		case 112: goto st150;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
	switch( (*p) ) {
		case 95: goto tr232;
		case 101: goto tr327;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
	switch( (*p) ) {
		case 95: goto tr232;
		case 111: goto st152;
		case 114: goto st153;
		case 120: goto st154;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
	switch( (*p) ) {
		case 95: goto tr232;
		case 102: goto tr331;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
	switch( (*p) ) {
		case 95: goto tr232;
		case 114: goto tr332;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
	switch( (*p) ) {
		case 95: goto tr232;
		case 112: goto st155;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
	switch( (*p) ) {
		case 95: goto tr232;
		case 111: goto st156;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
	switch( (*p) ) {
		case 95: goto tr232;
		case 114: goto st157;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
	switch( (*p) ) {
		case 95: goto tr232;
		case 116: goto tr336;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
	switch( (*p) ) {
		case 95: goto tr232;
		case 114: goto st159;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
	switch( (*p) ) {
		case 95: goto tr232;
		case 111: goto st160;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
	switch( (*p) ) {
		case 95: goto tr232;
		case 109: goto tr339;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
	switch( (*p) ) {
		case 95: goto tr232;
		case 101: goto st162;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
	switch( (*p) ) {
		case 95: goto tr232;
		case 116: goto st163;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
	switch( (*p) ) {
		case 95: goto tr232;
		case 107: goto st164;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
	switch( (*p) ) {
		case 95: goto tr232;
		case 101: goto st165;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
	switch( (*p) ) {
		case 95: goto tr232;
		case 121: goto tr344;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
	switch( (*p) ) {
		case 95: goto tr232;
		case 109: goto st167;
		case 110: goto st171;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
	switch( (*p) ) {
		case 95: goto tr232;
		case 112: goto st168;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
	switch( (*p) ) {
		case 95: goto tr232;
		case 111: goto st169;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
	switch( (*p) ) {
		case 95: goto tr232;
		case 114: goto st170;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
	switch( (*p) ) {
		case 95: goto tr232;
		case 116: goto tr350;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
	switch( (*p) ) {
		case 95: goto tr232;
		case 99: goto st172;
		case 119: goto st176;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
	switch( (*p) ) {
		case 95: goto tr232;
		case 108: goto st173;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
	switch( (*p) ) {
		case 95: goto tr232;
		case 117: goto st174;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
	switch( (*p) ) {
		case 95: goto tr232;
		case 100: goto st175;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
	switch( (*p) ) {
		case 95: goto tr232;
		case 101: goto tr356;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
	switch( (*p) ) {
		case 95: goto tr232;
		case 104: goto st177;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
	switch( (*p) ) {
		case 95: goto tr232;
		case 101: goto st178;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
	switch( (*p) ) {
		case 95: goto tr232;
		case 110: goto tr359;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
	switch( (*p) ) {
		case 95: goto tr232;
		case 101: goto st180;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
	switch( (*p) ) {
		case 95: goto tr232;
		case 114: goto st181;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
	switch( (*p) ) {
		case 95: goto tr232;
		case 114: goto tr362;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
	switch( (*p) ) {
		case 95: goto tr232;
		case 97: goto st183;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
	switch( (*p) ) {
		case 95: goto tr232;
		case 99: goto st184;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
	switch( (*p) ) {
		case 95: goto tr232;
		case 104: goto st185;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
	switch( (*p) ) {
		case 95: goto tr232;
		case 105: goto st186;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
	switch( (*p) ) {
		case 95: goto tr232;
		case 110: goto st187;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
	switch( (*p) ) {
		case 95: goto tr232;
		case 101: goto tr368;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
	switch( (*p) ) {
		case 95: goto tr232;
		case 102: goto st189;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
	switch( (*p) ) {
		case 95: goto tr232;
		case 97: goto st190;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
	switch( (*p) ) {
		case 95: goto tr232;
		case 112: goto st191;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
	switch( (*p) ) {
		case 95: goto tr232;
		case 111: goto st192;
		case 114: goto st197;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
	switch( (*p) ) {
		case 95: goto tr232;
		case 115: goto st193;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
	switch( (*p) ) {
		case 95: goto tr232;
		case 116: goto st194;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
	switch( (*p) ) {
		case 95: goto tr232;
		case 112: goto st195;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
	switch( (*p) ) {
		case 95: goto tr232;
		case 111: goto st196;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
	switch( (*p) ) {
		case 95: goto tr232;
		case 112: goto tr378;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
	switch( (*p) ) {
		case 95: goto tr232;
		case 101: goto st198;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
	switch( (*p) ) {
		case 95: goto tr232;
		case 112: goto st199;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
	switch( (*p) ) {
		case 95: goto tr232;
		case 117: goto st200;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
	switch( (*p) ) {
		case 95: goto tr232;
		case 115: goto st201;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
	switch( (*p) ) {
		case 95: goto tr232;
		case 104: goto tr383;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
	switch( (*p) ) {
		case 95: goto tr232;
		case 117: goto st203;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
	switch( (*p) ) {
		case 95: goto tr232;
		case 116: goto st204;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
	switch( (*p) ) {
		case 95: goto tr232;
		case 119: goto st205;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
	switch( (*p) ) {
		case 95: goto tr232;
		case 104: goto st206;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
	switch( (*p) ) {
		case 95: goto tr232;
		case 101: goto st207;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
	switch( (*p) ) {
		case 95: goto tr232;
		case 110: goto tr389;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
	switch( (*p) ) {
		case 95: goto tr232;
		case 111: goto st209;
		case 114: goto st214;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
	switch( (*p) ) {
		case 95: goto tr232;
		case 115: goto st210;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
	switch( (*p) ) {
		case 95: goto tr232;
		case 116: goto st211;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
	switch( (*p) ) {
		case 95: goto tr232;
		case 112: goto st212;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
	switch( (*p) ) {
		case 95: goto tr232;
		case 111: goto st213;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
	switch( (*p) ) {
		case 95: goto tr232;
		case 112: goto tr396;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
	switch( (*p) ) {
		case 95: goto tr232;
		case 101: goto st215;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
	switch( (*p) ) {
		case 95: goto tr232;
		case 112: goto st216;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
	switch( (*p) ) {
		case 95: goto tr232;
		case 117: goto st217;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
	switch( (*p) ) {
		case 95: goto tr232;
		case 115: goto st218;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
	switch( (*p) ) {
		case 95: goto tr232;
		case 104: goto tr401;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
	switch( (*p) ) {
		case 95: goto tr232;
		case 111: goto tr402;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st220:
	if ( ++p == pe )
		goto _test_eof220;
case 220:
	switch( (*p) ) {
		case 95: goto tr232;
		case 97: goto st221;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
	switch( (*p) ) {
		case 95: goto tr232;
		case 114: goto st222;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st222:
	if ( ++p == pe )
		goto _test_eof222;
case 222:
	switch( (*p) ) {
		case 95: goto tr232;
		case 105: goto st223;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
	switch( (*p) ) {
		case 95: goto tr232;
		case 97: goto st224;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 98 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
	switch( (*p) ) {
		case 95: goto tr232;
		case 98: goto st225;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
	switch( (*p) ) {
		case 95: goto tr232;
		case 108: goto st226;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
	switch( (*p) ) {
		case 95: goto tr232;
		case 101: goto tr409;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
	switch( (*p) ) {
		case 95: goto tr232;
		case 104: goto st228;
		case 114: goto st230;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
	switch( (*p) ) {
		case 95: goto tr232;
		case 101: goto st229;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
	switch( (*p) ) {
		case 95: goto tr232;
		case 110: goto tr413;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
	switch( (*p) ) {
		case 95: goto tr232;
		case 105: goto st231;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
	switch( (*p) ) {
		case 95: goto tr232;
		case 116: goto st232;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st232:
	if ( ++p == pe )
		goto _test_eof232;
case 232:
	switch( (*p) ) {
		case 95: goto tr232;
		case 101: goto tr416;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr232;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr232;
	} else
		goto tr232;
	goto tr311;
st233:
	if ( ++p == pe )
		goto _test_eof233;
case 233:
	switch( (*p) ) {
		case 42: goto tr417;
		case 61: goto tr418;
	}
	goto tr251;
tr249:
#line 1 "NONE"
	{te = p+1;}
	goto st234;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
#line 6041 "rlscan.cc"
	if ( (*p) == 37 )
		goto st35;
	goto tr251;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
	if ( (*p) == 37 )
		goto tr58;
	goto tr30;
	}
	_test_eof36: cs = 36; goto _test_eof; 
	_test_eof37: cs = 37; goto _test_eof; 
	_test_eof38: cs = 38; goto _test_eof; 
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof39: cs = 39; goto _test_eof; 
	_test_eof40: cs = 40; goto _test_eof; 
	_test_eof41: cs = 41; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof42: cs = 42; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof43: cs = 43; goto _test_eof; 
	_test_eof44: cs = 44; goto _test_eof; 
	_test_eof45: cs = 45; goto _test_eof; 
	_test_eof46: cs = 46; goto _test_eof; 
	_test_eof47: cs = 47; goto _test_eof; 
	_test_eof48: cs = 48; goto _test_eof; 
	_test_eof49: cs = 49; goto _test_eof; 
	_test_eof50: cs = 50; goto _test_eof; 
	_test_eof51: cs = 51; goto _test_eof; 
	_test_eof52: cs = 52; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof53: cs = 53; goto _test_eof; 
	_test_eof54: cs = 54; goto _test_eof; 
	_test_eof55: cs = 55; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof56: cs = 56; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof57: cs = 57; goto _test_eof; 
	_test_eof58: cs = 58; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof59: cs = 59; goto _test_eof; 
	_test_eof60: cs = 60; goto _test_eof; 
	_test_eof61: cs = 61; goto _test_eof; 
	_test_eof62: cs = 62; goto _test_eof; 
	_test_eof63: cs = 63; goto _test_eof; 
	_test_eof64: cs = 64; goto _test_eof; 
	_test_eof65: cs = 65; goto _test_eof; 
	_test_eof66: cs = 66; goto _test_eof; 
	_test_eof67: cs = 67; goto _test_eof; 
	_test_eof68: cs = 68; goto _test_eof; 
	_test_eof69: cs = 69; goto _test_eof; 
	_test_eof70: cs = 70; goto _test_eof; 
	_test_eof71: cs = 71; goto _test_eof; 
	_test_eof72: cs = 72; goto _test_eof; 
	_test_eof73: cs = 73; goto _test_eof; 
	_test_eof74: cs = 74; goto _test_eof; 
	_test_eof75: cs = 75; goto _test_eof; 
	_test_eof76: cs = 76; goto _test_eof; 
	_test_eof77: cs = 77; goto _test_eof; 
	_test_eof78: cs = 78; goto _test_eof; 
	_test_eof79: cs = 79; goto _test_eof; 
	_test_eof80: cs = 80; goto _test_eof; 
	_test_eof81: cs = 81; goto _test_eof; 
	_test_eof82: cs = 82; goto _test_eof; 
	_test_eof83: cs = 83; goto _test_eof; 
	_test_eof84: cs = 84; goto _test_eof; 
	_test_eof85: cs = 85; goto _test_eof; 
	_test_eof86: cs = 86; goto _test_eof; 
	_test_eof87: cs = 87; goto _test_eof; 
	_test_eof88: cs = 88; goto _test_eof; 
	_test_eof89: cs = 89; goto _test_eof; 
	_test_eof90: cs = 90; goto _test_eof; 
	_test_eof91: cs = 91; goto _test_eof; 
	_test_eof92: cs = 92; goto _test_eof; 
	_test_eof93: cs = 93; goto _test_eof; 
	_test_eof94: cs = 94; goto _test_eof; 
	_test_eof95: cs = 95; goto _test_eof; 
	_test_eof96: cs = 96; goto _test_eof; 
	_test_eof97: cs = 97; goto _test_eof; 
	_test_eof98: cs = 98; goto _test_eof; 
	_test_eof99: cs = 99; goto _test_eof; 
	_test_eof100: cs = 100; goto _test_eof; 
	_test_eof101: cs = 101; goto _test_eof; 
	_test_eof102: cs = 102; goto _test_eof; 
	_test_eof103: cs = 103; goto _test_eof; 
	_test_eof104: cs = 104; goto _test_eof; 
	_test_eof105: cs = 105; goto _test_eof; 
	_test_eof106: cs = 106; goto _test_eof; 
	_test_eof107: cs = 107; goto _test_eof; 
	_test_eof108: cs = 108; goto _test_eof; 
	_test_eof109: cs = 109; goto _test_eof; 
	_test_eof110: cs = 110; goto _test_eof; 
	_test_eof111: cs = 111; goto _test_eof; 
	_test_eof112: cs = 112; goto _test_eof; 
	_test_eof113: cs = 113; goto _test_eof; 
	_test_eof114: cs = 114; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof115: cs = 115; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof116: cs = 116; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof117: cs = 117; goto _test_eof; 
	_test_eof118: cs = 118; goto _test_eof; 
	_test_eof119: cs = 119; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof120: cs = 120; goto _test_eof; 
	_test_eof121: cs = 121; goto _test_eof; 
	_test_eof122: cs = 122; goto _test_eof; 
	_test_eof123: cs = 123; goto _test_eof; 
	_test_eof124: cs = 124; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof125: cs = 125; goto _test_eof; 
	_test_eof126: cs = 126; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof127: cs = 127; goto _test_eof; 
	_test_eof128: cs = 128; goto _test_eof; 
	_test_eof129: cs = 129; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 
	_test_eof34: cs = 34; goto _test_eof; 
	_test_eof130: cs = 130; goto _test_eof; 
	_test_eof131: cs = 131; goto _test_eof; 
	_test_eof132: cs = 132; goto _test_eof; 
	_test_eof133: cs = 133; goto _test_eof; 
	_test_eof134: cs = 134; goto _test_eof; 
	_test_eof135: cs = 135; goto _test_eof; 
	_test_eof136: cs = 136; goto _test_eof; 
	_test_eof137: cs = 137; goto _test_eof; 
	_test_eof138: cs = 138; goto _test_eof; 
	_test_eof139: cs = 139; goto _test_eof; 
	_test_eof140: cs = 140; goto _test_eof; 
	_test_eof141: cs = 141; goto _test_eof; 
	_test_eof142: cs = 142; goto _test_eof; 
	_test_eof143: cs = 143; goto _test_eof; 
	_test_eof144: cs = 144; goto _test_eof; 
	_test_eof145: cs = 145; goto _test_eof; 
	_test_eof146: cs = 146; goto _test_eof; 
	_test_eof147: cs = 147; goto _test_eof; 
	_test_eof148: cs = 148; goto _test_eof; 
	_test_eof149: cs = 149; goto _test_eof; 
	_test_eof150: cs = 150; goto _test_eof; 
	_test_eof151: cs = 151; goto _test_eof; 
	_test_eof152: cs = 152; goto _test_eof; 
	_test_eof153: cs = 153; goto _test_eof; 
	_test_eof154: cs = 154; goto _test_eof; 
	_test_eof155: cs = 155; goto _test_eof; 
	_test_eof156: cs = 156; goto _test_eof; 
	_test_eof157: cs = 157; goto _test_eof; 
	_test_eof158: cs = 158; goto _test_eof; 
	_test_eof159: cs = 159; goto _test_eof; 
	_test_eof160: cs = 160; goto _test_eof; 
	_test_eof161: cs = 161; goto _test_eof; 
	_test_eof162: cs = 162; goto _test_eof; 
	_test_eof163: cs = 163; goto _test_eof; 
	_test_eof164: cs = 164; goto _test_eof; 
	_test_eof165: cs = 165; goto _test_eof; 
	_test_eof166: cs = 166; goto _test_eof; 
	_test_eof167: cs = 167; goto _test_eof; 
	_test_eof168: cs = 168; goto _test_eof; 
	_test_eof169: cs = 169; goto _test_eof; 
	_test_eof170: cs = 170; goto _test_eof; 
	_test_eof171: cs = 171; goto _test_eof; 
	_test_eof172: cs = 172; goto _test_eof; 
	_test_eof173: cs = 173; goto _test_eof; 
	_test_eof174: cs = 174; goto _test_eof; 
	_test_eof175: cs = 175; goto _test_eof; 
	_test_eof176: cs = 176; goto _test_eof; 
	_test_eof177: cs = 177; goto _test_eof; 
	_test_eof178: cs = 178; goto _test_eof; 
	_test_eof179: cs = 179; goto _test_eof; 
	_test_eof180: cs = 180; goto _test_eof; 
	_test_eof181: cs = 181; goto _test_eof; 
	_test_eof182: cs = 182; goto _test_eof; 
	_test_eof183: cs = 183; goto _test_eof; 
	_test_eof184: cs = 184; goto _test_eof; 
	_test_eof185: cs = 185; goto _test_eof; 
	_test_eof186: cs = 186; goto _test_eof; 
	_test_eof187: cs = 187; goto _test_eof; 
	_test_eof188: cs = 188; goto _test_eof; 
	_test_eof189: cs = 189; goto _test_eof; 
	_test_eof190: cs = 190; goto _test_eof; 
	_test_eof191: cs = 191; goto _test_eof; 
	_test_eof192: cs = 192; goto _test_eof; 
	_test_eof193: cs = 193; goto _test_eof; 
	_test_eof194: cs = 194; goto _test_eof; 
	_test_eof195: cs = 195; goto _test_eof; 
	_test_eof196: cs = 196; goto _test_eof; 
	_test_eof197: cs = 197; goto _test_eof; 
	_test_eof198: cs = 198; goto _test_eof; 
	_test_eof199: cs = 199; goto _test_eof; 
	_test_eof200: cs = 200; goto _test_eof; 
	_test_eof201: cs = 201; goto _test_eof; 
	_test_eof202: cs = 202; goto _test_eof; 
	_test_eof203: cs = 203; goto _test_eof; 
	_test_eof204: cs = 204; goto _test_eof; 
	_test_eof205: cs = 205; goto _test_eof; 
	_test_eof206: cs = 206; goto _test_eof; 
	_test_eof207: cs = 207; goto _test_eof; 
	_test_eof208: cs = 208; goto _test_eof; 
	_test_eof209: cs = 209; goto _test_eof; 
	_test_eof210: cs = 210; goto _test_eof; 
	_test_eof211: cs = 211; goto _test_eof; 
	_test_eof212: cs = 212; goto _test_eof; 
	_test_eof213: cs = 213; goto _test_eof; 
	_test_eof214: cs = 214; goto _test_eof; 
	_test_eof215: cs = 215; goto _test_eof; 
	_test_eof216: cs = 216; goto _test_eof; 
	_test_eof217: cs = 217; goto _test_eof; 
	_test_eof218: cs = 218; goto _test_eof; 
	_test_eof219: cs = 219; goto _test_eof; 
	_test_eof220: cs = 220; goto _test_eof; 
	_test_eof221: cs = 221; goto _test_eof; 
	_test_eof222: cs = 222; goto _test_eof; 
	_test_eof223: cs = 223; goto _test_eof; 
	_test_eof224: cs = 224; goto _test_eof; 
	_test_eof225: cs = 225; goto _test_eof; 
	_test_eof226: cs = 226; goto _test_eof; 
	_test_eof227: cs = 227; goto _test_eof; 
	_test_eof228: cs = 228; goto _test_eof; 
	_test_eof229: cs = 229; goto _test_eof; 
	_test_eof230: cs = 230; goto _test_eof; 
	_test_eof231: cs = 231; goto _test_eof; 
	_test_eof232: cs = 232; goto _test_eof; 
	_test_eof233: cs = 233; goto _test_eof; 
	_test_eof234: cs = 234; goto _test_eof; 
	_test_eof35: cs = 35; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 37: goto tr70;
	case 38: goto tr71;
	case 1: goto tr0;
	case 2: goto tr0;
	case 39: goto tr71;
	case 40: goto tr73;
	case 41: goto tr71;
	case 3: goto tr0;
	case 4: goto tr0;
	case 42: goto tr71;
	case 5: goto tr0;
	case 6: goto tr0;
	case 7: goto tr0;
	case 43: goto tr75;
	case 44: goto tr76;
	case 45: goto tr77;
	case 46: goto tr77;
	case 47: goto tr77;
	case 48: goto tr77;
	case 49: goto tr77;
	case 51: goto tr101;
	case 52: goto tr102;
	case 8: goto tr14;
	case 9: goto tr14;
	case 53: goto tr102;
	case 54: goto tr104;
	case 55: goto tr102;
	case 10: goto tr14;
	case 11: goto tr14;
	case 56: goto tr102;
	case 12: goto tr14;
	case 13: goto tr14;
	case 14: goto tr14;
	case 57: goto tr105;
	case 58: goto tr105;
	case 15: goto tr28;
	case 59: goto tr107;
	case 60: goto tr102;
	case 61: goto tr109;
	case 62: goto tr110;
	case 63: goto tr110;
	case 64: goto tr110;
	case 65: goto tr110;
	case 66: goto tr110;
	case 67: goto tr124;
	case 68: goto tr110;
	case 69: goto tr110;
	case 70: goto tr110;
	case 71: goto tr110;
	case 72: goto tr110;
	case 73: goto tr110;
	case 74: goto tr110;
	case 75: goto tr110;
	case 76: goto tr110;
	case 77: goto tr110;
	case 78: goto tr110;
	case 79: goto tr110;
	case 80: goto tr110;
	case 81: goto tr110;
	case 82: goto tr110;
	case 83: goto tr110;
	case 84: goto tr110;
	case 85: goto tr110;
	case 86: goto tr110;
	case 87: goto tr110;
	case 88: goto tr110;
	case 89: goto tr110;
	case 90: goto tr110;
	case 91: goto tr110;
	case 92: goto tr110;
	case 93: goto tr110;
	case 94: goto tr110;
	case 95: goto tr110;
	case 96: goto tr110;
	case 97: goto tr110;
	case 98: goto tr110;
	case 99: goto tr110;
	case 100: goto tr110;
	case 101: goto tr110;
	case 102: goto tr110;
	case 104: goto tr171;
	case 106: goto tr189;
	case 107: goto tr191;
	case 108: goto tr193;
	case 110: goto tr209;
	case 111: goto tr210;
	case 113: goto tr250;
	case 114: goto tr251;
	case 16: goto tr30;
	case 115: goto tr252;
	case 17: goto tr30;
	case 116: goto tr251;
	case 18: goto tr30;
	case 117: goto tr251;
	case 118: goto tr251;
	case 119: goto tr251;
	case 19: goto tr30;
	case 20: goto tr30;
	case 120: goto tr251;
	case 121: goto tr251;
	case 122: goto tr251;
	case 123: goto tr251;
	case 124: goto tr271;
	case 21: goto tr40;
	case 125: goto tr273;
	case 126: goto tr273;
	case 22: goto tr42;
	case 127: goto tr275;
	case 128: goto tr251;
	case 129: goto tr281;
	case 23: goto tr30;
	case 24: goto tr30;
	case 25: goto tr30;
	case 26: goto tr30;
	case 27: goto tr30;
	case 28: goto tr30;
	case 29: goto tr30;
	case 30: goto tr30;
	case 31: goto tr30;
	case 32: goto tr30;
	case 33: goto tr30;
	case 34: goto tr30;
	case 130: goto tr251;
	case 131: goto tr290;
	case 132: goto tr251;
	case 133: goto tr251;
	case 134: goto tr251;
	case 135: goto tr308;
	case 136: goto tr309;
	case 137: goto tr311;
	case 138: goto tr311;
	case 139: goto tr311;
	case 140: goto tr311;
	case 141: goto tr311;
	case 142: goto tr311;
	case 143: goto tr311;
	case 144: goto tr311;
	case 145: goto tr311;
	case 146: goto tr311;
	case 147: goto tr311;
	case 148: goto tr311;
	case 149: goto tr311;
	case 150: goto tr311;
	case 151: goto tr311;
	case 152: goto tr311;
	case 153: goto tr311;
	case 154: goto tr311;
	case 155: goto tr311;
	case 156: goto tr311;
	case 157: goto tr311;
	case 158: goto tr311;
	case 159: goto tr311;
	case 160: goto tr311;
	case 161: goto tr311;
	case 162: goto tr311;
	case 163: goto tr311;
	case 164: goto tr311;
	case 165: goto tr311;
	case 166: goto tr311;
	case 167: goto tr311;
	case 168: goto tr311;
	case 169: goto tr311;
	case 170: goto tr311;
	case 171: goto tr311;
	case 172: goto tr311;
	case 173: goto tr311;
	case 174: goto tr311;
	case 175: goto tr311;
	case 176: goto tr311;
	case 177: goto tr311;
	case 178: goto tr311;
	case 179: goto tr311;
	case 180: goto tr311;
	case 181: goto tr311;
	case 182: goto tr311;
	case 183: goto tr311;
	case 184: goto tr311;
	case 185: goto tr311;
	case 186: goto tr311;
	case 187: goto tr311;
	case 188: goto tr311;
	case 189: goto tr311;
	case 190: goto tr311;
	case 191: goto tr311;
	case 192: goto tr311;
	case 193: goto tr311;
	case 194: goto tr311;
	case 195: goto tr311;
	case 196: goto tr311;
	case 197: goto tr311;
	case 198: goto tr311;
	case 199: goto tr311;
	case 200: goto tr311;
	case 201: goto tr311;
	case 202: goto tr311;
	case 203: goto tr311;
	case 204: goto tr311;
	case 205: goto tr311;
	case 206: goto tr311;
	case 207: goto tr311;
	case 208: goto tr311;
	case 209: goto tr311;
	case 210: goto tr311;
	case 211: goto tr311;
	case 212: goto tr311;
	case 213: goto tr311;
	case 214: goto tr311;
	case 215: goto tr311;
	case 216: goto tr311;
	case 217: goto tr311;
	case 218: goto tr311;
	case 219: goto tr311;
	case 220: goto tr311;
	case 221: goto tr311;
	case 222: goto tr311;
	case 223: goto tr311;
	case 224: goto tr311;
	case 225: goto tr311;
	case 226: goto tr311;
	case 227: goto tr311;
	case 228: goto tr311;
	case 229: goto tr311;
	case 230: goto tr311;
	case 231: goto tr311;
	case 232: goto tr311;
	case 233: goto tr251;
	case 234: goto tr251;
	case 35: goto tr30;
	}
	}

	_out: {}
	}

#line 1264 "rlscan.rl"

		/* Check if we failed. */
		if ( cs == rlscan_error ) {
			/* Machine failed before finding a token. I'm not yet sure if this
			 * is reachable. */
			scan_error() << "scanner error" << endl;
			exit(1);
		}

		/* Decide if we need to preserve anything. */
		char *preserve = ts;

		/* Now set up the prefix. */
		if ( preserve == 0 )
			have = 0;
		else {
			/* There is data that needs to be shifted over. */
			have = pe - preserve;
			memmove( buf, preserve, have );
			unsigned int shiftback = preserve - buf;
			if ( ts != 0 )
				ts -= shiftback;
			te -= shiftback;

			preserve = buf;
		}
	}

	delete[] buf;
}

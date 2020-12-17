#include <expat.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static const char* xml =
    "<data>\n"\
    "    <header length=\"4\">\n"\
    "            <item name=\"time\" type=\"time\">16</item>\n"\
    "            <item name=\"ref\" type=\"string\">3843747</item>\n"\
    "            <item name=\"port\" type=\"int16\">0</item>\n"\
    "            <item name=\"frame\" type=\"int16\">20</item>\n"\
    "    </header>\n"\
    "</data>\n";

void reset_char_data_buffer ();
void process_char_data_buffer ();
static bool grab_next_value;

void start_element(void *data, const char *element, const char **attribute) {
    process_char_data_buffer();
    reset_char_data_buffer();

    if ( strcmp("item", element) == 0 ) {
        size_t matched = 0;

        for (size_t i = 0; attribute[i]; i += 2) {
            if ( ( strcmp("name", attribute[i]) == 0 ) && ( strcmp("frame", attribute[i+1]) == 0 ) )
                ++matched;

            if ( ( strcmp("type", attribute[i]) == 0 ) && ( strcmp("int16", attribute[i+1]) == 0 ) )
                ++matched;
        }

        if (matched == 2) {
            printf("this is the element you are looking for\n");
            grab_next_value = true;
        }
    }
}

void end_element(void *data, const char *el) {
    process_char_data_buffer();
    reset_char_data_buffer();
}

static char char_data_buffer[1024];
static size_t offs;
static bool overflow;

void reset_char_data_buffer (void) {
    offs = 0;
    overflow = false;
    grab_next_value = false;
}

// pastes parts of the node together
void char_data (void *userData, const XML_Char *s, int len) {
    if (!overflow) {
        if (len + offs >= sizeof(char_data_buffer) ) {
            overflow = true;
        } else {
            memcpy(char_data_buffer + offs, s, len);
            offs += len;
        }
    }
}

// if the element is the one we're after, convert the character data to
// an integer value
void process_char_data_buffer (void) {
    if (offs > 0) {
        char_data_buffer[ offs ] = '\0';

        printf("character data: %s\n", char_data_buffer);

        if ( grab_next_value ) {
            int value = atoi( char_data_buffer );

            printf("the value is %d\n", value);
        }
    }
}

int main (void ) {
	
	printf("This code was written by Kraken175, https://bit.ly/3ntNKY2");
	system("timeout /t 5 /nobreak>nul");
    XML_Parser parser = XML_ParserCreate(NULL);

    XML_SetElementHandler(parser, start_element, end_element);
    XML_SetCharacterDataHandler(parser, char_data);

    reset_char_data_buffer();

    if (XML_Parse(parser, xml, strlen(xml), XML_TRUE) == XML_STATUS_ERROR)
        printf("Error: %s\n", XML_ErrorString(XML_GetErrorCode(parser)));

    XML_ParserFree(parser);

    return 0;
}
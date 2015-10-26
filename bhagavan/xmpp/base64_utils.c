#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include "stdio.h"
#include "string.h"

static char encoding_table[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
	'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
	'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
	'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
	'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
	'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
	'w', 'x', 'y', 'z', '0', '1', '2', '3',
	'4', '5', '6', '7', '8', '9', '+', '/'};
static char *decoding_table = NULL;
static int mod_table[] = {0, 2, 1};

char *base64_encode(const char *data, size_t input_length, size_t *output_length) 
{
	int i, j;

	*output_length = (size_t) (4.0 * ceil((double) input_length / 3.0));

	char *encoded_data = malloc(*output_length);
	if (encoded_data == NULL) return NULL;

	for (i = 0, j = 0; i < input_length;) 
	{

		uint32_t octet_a = i < input_length ? data[i++] : 0;
		uint32_t octet_b = i < input_length ? data[i++] : 0;
		uint32_t octet_c = i < input_length ? data[i++] : 0;

		uint32_t triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;

		encoded_data[j++] = encoding_table[(triple >> 3 * 6) & 0x3F];
		encoded_data[j++] = encoding_table[(triple >> 2 * 6) & 0x3F];
		encoded_data[j++] = encoding_table[(triple >> 1 * 6) & 0x3F];
		encoded_data[j++] = encoding_table[(triple >> 0 * 6) & 0x3F];
	}

	for (i = 0; i < mod_table[input_length % 3]; i++)
		encoded_data[*output_length - 1 - i] = '=';

	return encoded_data;
}

void build_decoding_table()
{
	int i;

	decoding_table = malloc(256);

	for (i = 0; i < 0x40; i++)
		decoding_table[(int)encoding_table[i]] = i;
}

char *base64_decode(const char *data, size_t input_length, size_t *output_length) 
{
	int i, j;

	if (decoding_table == NULL) 
		build_decoding_table();

	if (input_length % 4 != 0) 
		return NULL;

	*output_length = input_length / 4 * 3;
	if (data[input_length - 1] == '=') (*output_length)--;
	if (data[input_length - 2] == '=') (*output_length)--;

	char *decoded_data = malloc(*output_length);
	if (decoded_data == NULL) 
		return NULL;

	for (i = 0, j = 0; i < input_length;) 
	{
		uint32_t sextet_a = data[i] == '=' ? 0 & i++ : decoding_table[(int)data[i++]];
		uint32_t sextet_b = data[i] == '=' ? 0 & i++ : decoding_table[(int)data[i++]];
		uint32_t sextet_c = data[i] == '=' ? 0 & i++ : decoding_table[(int)data[i++]];
		uint32_t sextet_d = data[i] == '=' ? 0 & i++ : decoding_table[(int)data[i++]];

		uint32_t triple = (sextet_a << 3 * 6)
			+ (sextet_b << 2 * 6)
			+ (sextet_c << 1 * 6)
			+ (sextet_d << 0 * 6);

		if (j < *output_length) decoded_data[j++] = (triple >> 2 * 8) & 0xFF;
		if (j < *output_length) decoded_data[j++] = (triple >> 1 * 8) & 0xFF;
		if (j < *output_length) decoded_data[j++] = (triple >> 0 * 8) & 0xFF;
	}

	return decoded_data;
}


void base64_cleanup() 
{
	free(decoding_table);
}

int encode(char *user, char *pass)
{
	int ol, i;
	char *p;
	char new_str[1024];
	int ulen = 0, plen = 0, nstr_len = 0;

	ulen = strlen(user);
	plen = strlen(pass);
	nstr_len = ulen + plen + 2;

	new_str[0] = 0;
	strncpy(new_str+1, user, ulen);
	new_str[1+ulen] = 0;
	strncpy(new_str+1+ulen+1, pass, plen);

	p = base64_encode(new_str, nstr_len, (size_t *)&ol);
	printf("-->Encoding value of 0%s0%s is :", user, pass);
	for (i = 0; i < ol; i++)
		printf("%c", p[i]);
	printf("\n");

	return 0;
}

char * base16_encode(char *data, int len)
{
	int i;
	char *ascii = NULL;

	//g_return_val_if_fail(data != NULL, NULL);
	//g_return_val_if_fail(len > 0,   NULL);

	ascii = malloc(len * 2 + 1);

	for (i = 0; i < len; i++)
		snprintf(&ascii[i * 2], 3, "%02hhx", data[i]);

	return ascii;
}


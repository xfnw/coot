#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define SW switch (c = getchar())
#define DG(d) \
	case EOF: d break; \
	case ' ': d goto new; \
	case '\n': d putchar('\n'); goto new; \
	case '/': d putchar(' '); goto new; \
	default: tomorse(c); goto new;
#define DR(d) DG(putchar(d););
#define DO(d) \
	SW { DR(d) }

char *morseify(char c) {
	switch (isupper(c) ? c | 32 : c) {
	case '!': return "-.-.-- "; break;
	case '"': return ".-..-. "; break;
	case '#': return "....-- "; break;
	case '$': return "...-..- "; break;
	case '%': return ".--..-. "; break;
	case '&': return ".-... "; break;
	case '\'': return ".----. "; break;
	case '(': return "-.--. "; break;
	case ')': return "-.--.- "; break;
	case '*': return "-.-.- "; break;
	case '+': return ".-.-. "; break;
	case ',': return "--..-- "; break;
	case '-': return "-....- "; break; /* unreachable if first */
	case '.': return ".-.-.- "; break; /* same here */
	case '/': return "-..-. "; break;  /* me too */
	case '0': return "----- "; break;
	case '1': return ".---- "; break;
	case '2': return "..--- "; break;
	case '3': return "...-- "; break;
	case '4': return "....- "; break;
	case '5': return "..... "; break;
	case '6': return "-.... "; break;
	case '7': return "--... "; break;
	case '8': return "---.. "; break;
	case '9': return "----. "; break;
	case ':': return "---... "; break;
	case ';': return "-.-.-. "; break;
	case '<': return "--.-- "; break;
	case '=': return "-...- "; break;
	case '>': return "--.--. "; break;
	case '?': return "..--.. "; break;
	case '@': return ".--.-. "; break;
	case '[': return "..-.. "; break;
	case '\\': return ".-..- "; break;
	case ']': return "..-..- "; break;
	case '^': return ".--.--- "; break;
	case '_': return "..--.- "; break;
	case 'a': return ".- "; break;
	case 'b': return "-... "; break;
	case 'c': return "-.-. "; break;
	case 'd': return "-.. "; break;
	case 'e': return ". "; break;
	case 'f': return "..-. "; break;
	case 'g': return "--. "; break;
	case 'h': return ".... "; break;
	case 'i': return ".. "; break;
	case 'j': return ".--- "; break;
	case 'k': return "-.- "; break;
	case 'l': return ".-.. "; break;
	case 'm': return "-- "; break;
	case 'n': return "-. "; break;
	case 'o': return "--- "; break;
	case 'p': return ".--. "; break;
	case 'q': return "--.- "; break;
	case 'r': return ".-. "; break;
	case 's': return "... "; break;
	case 't': return "- "; break;
	case 'u': return "..- "; break;
	case 'v': return "...- "; break;
	case 'w': return ".-- "; break;
	case 'x': return "-..- "; break;
	case 'y': return "-.-- "; break;
	case 'z': return "--.. "; break;
	case '{': return ".--.- "; break;
	case '|': return ".--... "; break;
	case '}': return ".--.-- "; break;
	case '~': return "...--.- "; break;
	default: return NULL;
	}
}

void tomorse(char c) {
	for (;;) {
		if (c == EOF)
			exit(0);

		char *out = morseify(c);
		if (out == NULL) {
			switch (c) {
			case ' ': out = " / "; break;
			case '\n': out = "\n"; break;
			default: out = "ERR "; break;
			}
			fputs(out, stdout);
			return;
		}
		fputs(out, stdout);
		c = getchar();
	}
}

int main() {
	char c;

	/* clang-format off */
	new : SW { DG(;)
	case '.':
		SW { DR('e')
		case '.':
			SW { DR('i')
			case '.':
				SW { DR('s')
				case '.':
					SW { DR('h')
					case '.':
						SW { DR('5')
							case '.':
								SW { DG(;)
								case '.':
									SW { DG(;)
									case '.': DO('\b')
									}
								}
						}
						break;
					case '-':
						SW { DR('4')
						case '-': DO('#')
						}
					}
					break;
				case '-':
					SW { DR('v')
					case '.':
						SW { DG(fputs("VERIFY ", stdout);)
						case '.':
							SW { DG(;)
							case '-': DO('$');
							}
							break;
						case '-':
							SW { DG(fputs("GOODBYE ", stdout);) }
						}
						break;
					case '-':
						SW { DR('3')
						case '.':
							SW { DG(;)
							case '-': DO('~')
							}
						}
					}
				}
				break;
			case '-':
				SW { DR('u')
				case '.':
					SW { DR('f')
					case '.':
						SW { DR('[')
						case '-': DO(']')
						}
						break;
					case '-':
						SW { DG(fputs("PLS RPT", stdout);) }
					}
					break;
				case '-':
					SW { DG(;)
					case '.':
						SW { DG(;)
						case '.': DO('?'); break;
						case '-': DO('_')
						}
						break;
					case '-':
						DO('2');
					}
				}
			}
			break;
		case '-':
			SW { DR('a')
			case '.':
				SW { DR('r')
				case '.':
					SW { DR('l')
					case '.': DO('&'); break;
					case '-':
						SW { DR('\\')
						case '.': DO('"')
						}
					}
					break;
				case '-':
					SW { DR('\n')
					case '.':
						SW { DR('+')
						case '-': DO('.')
						}
					}
				}
				break;
			case '-':
				SW { DR('w')
				case '.':
					SW { DR('p')
					case '.':
						SW { DG(;)
						case '.': DO('|'); break;
						case '-':
							SW { DG(;)
							case '.': DO('%')
							}
						}
						break;
					case '-':
						SW { DR('{')
						case '.': DO('@'); break;
						case '-':
							SW { DR('}')
							case '-': DO('^')
							}
						}
					}
					break;
				case '-':
					SW { DR('j')
					case '-':
						SW { DR('1')
						case '.': DO('\'')
						}
					}
				}
			}
		}
	case '-':
		SW { DR('t')
		case '.':
			SW { DR('n')
			case '.':
				SW { DR('d')
				case '.':
					SW { DR('b')
					case '.':
						SW { DR('6')
						case '-': DO('-')
						}
						break;
					case '-': DO('=')
					}
					break;
				case '-':
					SW { DR('x')
					case '.': DO('/')
					}
				}
				break;
			case '-':
				SW { DR('k')
				case '.':
					SW { DR('c')
					case '-':
						SW { DR('*')
						case '.': DO(';'); break;
						case '-': DO('!')
						}
					}
					break;
				case '-':
					SW { DR('y')
					case '.':
						SW { DR('(')
						case '-': DO(')')
						}
					}
				}
			}
			break;
		case '-':
			SW { DR('m')
			case '.':
				SW { DR('g')
				case '.':
					SW { DR('z')
					case '.': DO('7'); break;
					case '-':
						SW { DG(;)
						case '-': DO(',')
						}
					}
					break;
				case '-':
					SW { DR('q')
					case '-':
						SW { DR('<')
						case '.': DO('>')
						}
					}
				}
				break;
			case '-':
				SW { DR('o')
				case '.':
					SW { DG(;)
					case '.':
						SW { DR('8')
						case '.': DO(':')
						}
					}
					break;
				case '-':
					SW { DG(;)
					case '.': DO('9'); break;
					case '-': DO('0')
					}
				}
			}
		}
	}
	/* clang-format on */
}

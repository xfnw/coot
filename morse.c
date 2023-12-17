#include <stdio.h>

#define SW switch (c = getchar())
#define DG(d) \
	case EOF: d break; \
	case ' ': d goto new; \
	case '\n': d putchar('\n'); goto new; \
	case '/': d putchar(' '); goto new; \
	default: fputs(morseify(c),stdout); goto new;
#define DR(d) DG(putchar(d););
#define DO(d) SW { DR(d) }

char *morseify(char c) {
	switch (c|32) {
	case 'a': return ".- "; break;
	default: return "ERR ";
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
					case '-': DO('4');
					}
					break;
				case '-':
					SW { DR('v')
					case '.':
						SW { DG(fputs("VERIFY ", stdout);)
						case '-':
							SW { DG(fputs("END WORK ", stdout);) }
						}
						break;
					case '-': DO('3');
					}
				}
				break;
			case '-':
				SW { DR('u')
				case '.': DO('f'); break;
				case '-':
					SW { DG(;)
					case '.':
						SW { DG(;)
						case '.': DO('?');
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
					case '.':
						SW { DG(fputs("WAIT ", stdout);) }
						break;
					case '-':
						SW { DG(;)
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
					case '-':
						SW { DG(;)
						case '.': DO('@')
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
						SW { DG(fputs("BGN MSGS ", stdout);)
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
				case '-': DO('q')
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

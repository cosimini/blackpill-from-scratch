#include <stdint.h>

//extern unsigned int _stack_reset_value;
const uint32_t RAM_END = 0x2001ffff;

// Forward declarations
int  main(void);  // Main function defined in src/main.c
void rsth(void);  // Reset handler, defined below
void init(void);  // Init function defined in src/init.c
void trap(void);  // Trap execution indefietely
void noop(void);  // Do absolutely nothing

// The vector table
uint32_t __attribute__((section(".reset_vector"))) isr_vector[] = {
  (uint32_t) RAM_END,  //   0 - Initial SP value
  (uint32_t) rsth,     //   1 - Reset handler
  (uint32_t) noop,     //   2 - NMI
  (uint32_t) trap,     //   3 - Hard fault handler
  (uint32_t) trap,     //   4 - Memory management fault
  (uint32_t) trap,     //   5 - Bus fault
  (uint32_t) trap,     //   6 - Usage fault
  (uint32_t) 0,        //   7 - reserved
  (uint32_t) 0,        //   8 - reserved
  (uint32_t) 0,        //   9 - reserved
  (uint32_t) 0,        //  10 - reserved
  (uint32_t) noop,     //  11 - SVCall
  (uint32_t) 0,        //  12 - reserved
  (uint32_t) 0,        //  13 - reserved
  (uint32_t) noop,     //  14 - PendSV
  (uint32_t) noop,     //  15 - SysTick
  (uint32_t) noop,     //  16 - IRQ 0
  (uint32_t) noop,     //  17 - IRQ 1
  (uint32_t) noop,     //  18 - IRQ 2
  (uint32_t) noop,     //  19 - IRQ 3
  (uint32_t) noop,     //  20 - IRQ 4
  (uint32_t) noop,     //  21 - IRQ 5
  (uint32_t) noop,     //  22 - IRQ 6
  (uint32_t) noop,     //  23 - IRQ 7
  (uint32_t) noop,     //  24 - IRQ 8
  (uint32_t) noop,     //  25 - IRQ 9
  (uint32_t) noop,     //  26 - IRQ 10
  (uint32_t) noop,     //  27 - IRQ 11
  (uint32_t) noop,     //  28 - IRQ 12
  (uint32_t) noop,     //  29 - IRQ 13
  (uint32_t) noop,     //  30 - IRQ 14
  (uint32_t) noop,     //  31 - IRQ 15
  (uint32_t) noop,     //  32 - IRQ 16
  (uint32_t) noop,     //  33 - IRQ 17
  (uint32_t) noop,     //  34 - IRQ 18
  (uint32_t) noop,     //  35 - IRQ 19
  (uint32_t) noop,     //  36 - IRQ 20
  (uint32_t) noop,     //  37 - IRQ 21
  (uint32_t) noop,     //  38 - IRQ 22
  (uint32_t) noop,     //  39 - IRQ 23
  (uint32_t) noop,     //  40 - IRQ 24
  (uint32_t) noop,     //  41 - IRQ 25
  (uint32_t) noop,     //  42 - IRQ 26
  (uint32_t) noop,     //  43 - IRQ 27
  (uint32_t) noop,     //  44 - IRQ 28
  (uint32_t) noop,     //  45 - IRQ 29
  (uint32_t) noop,     //  46 - IRQ 30
  (uint32_t) noop,     //  47 - IRQ 31
  (uint32_t) noop,     //  48 - IRQ 32
  (uint32_t) noop,     //  49 - IRQ 33
  (uint32_t) noop,     //  50 - IRQ 34
  (uint32_t) noop,     //  51 - IRQ 35
  (uint32_t) noop,     //  52 - IRQ 36
  (uint32_t) noop,     //  53 - IRQ 37
  (uint32_t) noop,     //  54 - IRQ 38
  (uint32_t) noop,     //  55 - IRQ 39
  (uint32_t) noop,     //  56 - IRQ 40
  (uint32_t) noop,     //  57 - IRQ 41
  (uint32_t) noop,     //  58 - IRQ 42
  (uint32_t) noop,     //  59 - IRQ 43
  (uint32_t) noop,     //  60 - IRQ 44
  (uint32_t) noop,     //  61 - IRQ 45
  (uint32_t) noop,     //  62 - IRQ 46
  (uint32_t) noop,     //  63 - IRQ 47
  (uint32_t) noop,     //  64 - IRQ 48
  (uint32_t) noop,     //  65 - IRQ 49
  (uint32_t) noop,     //  66 - IRQ 50
  (uint32_t) noop,     //  67 - IRQ 51
  (uint32_t) noop,     //  68 - IRQ 52
  (uint32_t) noop,     //  69 - IRQ 53
  (uint32_t) noop,     //  70 - IRQ 54
  (uint32_t) noop,     //  71 - IRQ 55
  (uint32_t) noop,     //  72 - IRQ 56
  (uint32_t) noop,     //  73 - IRQ 57
  (uint32_t) noop,     //  74 - IRQ 58
  (uint32_t) noop,     //  75 - IRQ 59
  (uint32_t) noop,     //  76 - IRQ 60
  (uint32_t) noop,     //  77 - IRQ 61
  (uint32_t) noop,     //  78 - IRQ 62
  (uint32_t) noop,     //  79 - IRQ 63
  (uint32_t) noop,     //  80 - IRQ 64
  (uint32_t) noop,     //  81 - IRQ 65
  (uint32_t) noop,     //  82 - IRQ 66
  (uint32_t) noop,     //  83 - IRQ 67
  (uint32_t) noop,     //  84 - IRQ 68
  (uint32_t) noop,     //  85 - IRQ 69
  (uint32_t) noop,     //  86 - IRQ 70
  (uint32_t) noop,     //  87 - IRQ 71
  (uint32_t) noop,     //  88 - IRQ 72
  (uint32_t) noop,     //  89 - IRQ 73
  (uint32_t) noop,     //  90 - IRQ 74
  (uint32_t) noop,     //  91 - IRQ 75
  (uint32_t) noop,     //  92 - IRQ 76
  (uint32_t) noop,     //  93 - IRQ 77
  (uint32_t) noop,     //  94 - IRQ 78
  (uint32_t) noop,     //  95 - IRQ 79
  (uint32_t) noop,     //  96 - IRQ 80
  (uint32_t) noop,     //  97 - IRQ 81
  (uint32_t) noop,     //  98 - IRQ 82
  (uint32_t) noop,     //  99 - IRQ 83
  (uint32_t) noop,     // 100 - IRQ 84
  (uint32_t) noop,     // 101 - IRQ 85
  (uint32_t) noop,     // 102 - IRQ 86
  (uint32_t) noop,     // 103 - IRQ 87
  (uint32_t) noop,     // 104 - IRQ 88
  (uint32_t) noop,     // 105 - IRQ 89
  (uint32_t) noop,     // 106 - IRQ 90
  (uint32_t) noop,     // 107 - IRQ 91
  (uint32_t) noop,     // 108 - IRQ 92
  (uint32_t) noop,     // 109 - IRQ 93
  (uint32_t) noop,     // 110 - IRQ 94
  (uint32_t) noop,     // 111 - IRQ 95
  (uint32_t) noop,     // 112 - IRQ 96
  (uint32_t) noop,     // 113 - IRQ 97
  (uint32_t) noop,     // 114 - IRQ 98
  (uint32_t) noop,     // 115 - IRQ 99
  (uint32_t) noop,     // 116 - IRQ 100
  (uint32_t) noop,     // 117 - IRQ 101
  (uint32_t) noop,     // 118 - IRQ 102
  (uint32_t) noop,     // 119 - IRQ 103
  (uint32_t) noop,     // 120 - IRQ 104
  (uint32_t) noop,     // 121 - IRQ 105
  (uint32_t) noop,     // 122 - IRQ 106
  (uint32_t) noop,     // 123 - IRQ 107
  (uint32_t) noop,     // 124 - IRQ 108
  (uint32_t) noop,     // 125 - IRQ 109
  (uint32_t) noop,     // 126 - IRQ 110
  (uint32_t) noop,     // 127 - IRQ 111
  (uint32_t) noop,     // 128 - IRQ 112
  (uint32_t) noop,     // 129 - IRQ 113
  (uint32_t) noop,     // 130 - IRQ 114
  (uint32_t) noop,     // 131 - IRQ 115
  (uint32_t) noop,     // 132 - IRQ 116
  (uint32_t) noop,     // 133 - IRQ 117
  (uint32_t) noop,     // 134 - IRQ 118
  (uint32_t) noop,     // 135 - IRQ 119
  (uint32_t) noop,     // 136 - IRQ 120
  (uint32_t) noop,     // 137 - IRQ 121
  (uint32_t) noop,     // 138 - IRQ 122
  (uint32_t) noop,     // 139 - IRQ 123
  (uint32_t) noop,     // 140 - IRQ 124
  (uint32_t) noop,     // 141 - IRQ 125
  (uint32_t) noop,     // 142 - IRQ 126
  (uint32_t) noop,     // 143 - IRQ 127
  (uint32_t) noop,     // 144 - IRQ 128
  (uint32_t) noop,     // 145 - IRQ 129
  (uint32_t) noop,     // 146 - IRQ 130
  (uint32_t) noop,     // 147 - IRQ 131
  (uint32_t) noop,     // 148 - IRQ 132
  (uint32_t) noop,     // 149 - IRQ 133
  (uint32_t) noop,     // 150 - IRQ 134
  (uint32_t) noop,     // 151 - IRQ 135
  (uint32_t) noop,     // 152 - IRQ 136
  (uint32_t) noop,     // 153 - IRQ 137
  (uint32_t) noop,     // 154 - IRQ 138
  (uint32_t) noop,     // 155 - IRQ 139
  (uint32_t) noop,     // 156 - IRQ 140
  (uint32_t) noop,     // 157 - IRQ 141
  (uint32_t) noop,     // 158 - IRQ 142
  (uint32_t) noop,     // 159 - IRQ 143
  (uint32_t) noop,     // 160 - IRQ 144
  (uint32_t) noop,     // 161 - IRQ 145
  (uint32_t) noop,     // 162 - IRQ 146
  (uint32_t) noop,     // 163 - IRQ 147
  (uint32_t) noop,     // 164 - IRQ 148
  (uint32_t) noop,     // 165 - IRQ 149
  (uint32_t) noop,     // 166 - IRQ 150
  (uint32_t) noop,     // 167 - IRQ 151
  (uint32_t) noop,     // 168 - IRQ 152
  (uint32_t) noop,     // 169 - IRQ 153
  (uint32_t) noop,     // 170 - IRQ 154
  (uint32_t) noop,     // 171 - IRQ 155
  (uint32_t) noop,     // 172 - IRQ 156
  (uint32_t) noop,     // 173 - IRQ 157
  (uint32_t) noop,     // 174 - IRQ 158
  (uint32_t) noop,     // 175 - IRQ 159
  (uint32_t) noop,     // 176 - IRQ 160
  (uint32_t) noop,     // 177 - IRQ 161
  (uint32_t) noop,     // 178 - IRQ 162
  (uint32_t) noop,     // 179 - IRQ 163
  (uint32_t) noop,     // 180 - IRQ 164
  (uint32_t) noop,     // 181 - IRQ 165
  (uint32_t) noop,     // 182 - IRQ 166
  (uint32_t) noop,     // 183 - IRQ 167
  (uint32_t) noop,     // 184 - IRQ 168
  (uint32_t) noop,     // 185 - IRQ 169
  (uint32_t) noop,     // 186 - IRQ 170
  (uint32_t) noop,     // 187 - IRQ 171
  (uint32_t) noop,     // 188 - IRQ 172
  (uint32_t) noop,     // 189 - IRQ 173
  (uint32_t) noop,     // 190 - IRQ 174
  (uint32_t) noop,     // 191 - IRQ 175
  (uint32_t) noop,     // 192 - IRQ 176
  (uint32_t) noop,     // 193 - IRQ 177
  (uint32_t) noop,     // 194 - IRQ 178
  (uint32_t) noop,     // 195 - IRQ 179
  (uint32_t) noop,     // 196 - IRQ 180
  (uint32_t) noop,     // 197 - IRQ 181
  (uint32_t) noop,     // 198 - IRQ 182
  (uint32_t) noop,     // 199 - IRQ 183
  (uint32_t) noop,     // 200 - IRQ 184
  (uint32_t) noop,     // 201 - IRQ 185
  (uint32_t) noop,     // 202 - IRQ 186
  (uint32_t) noop,     // 203 - IRQ 187
  (uint32_t) noop,     // 204 - IRQ 188
  (uint32_t) noop,     // 205 - IRQ 189
  (uint32_t) noop,     // 206 - IRQ 190
  (uint32_t) noop,     // 207 - IRQ 191
  (uint32_t) noop,     // 208 - IRQ 192
  (uint32_t) noop,     // 209 - IRQ 193
  (uint32_t) noop,     // 210 - IRQ 194
  (uint32_t) noop,     // 211 - IRQ 195
  (uint32_t) noop,     // 212 - IRQ 196
  (uint32_t) noop,     // 213 - IRQ 197
  (uint32_t) noop,     // 214 - IRQ 198
  (uint32_t) noop,     // 215 - IRQ 199
  (uint32_t) noop,     // 216 - IRQ 200
  (uint32_t) noop,     // 217 - IRQ 201
  (uint32_t) noop,     // 218 - IRQ 202
  (uint32_t) noop,     // 219 - IRQ 203
  (uint32_t) noop,     // 220 - IRQ 204
  (uint32_t) noop,     // 221 - IRQ 205
  (uint32_t) noop,     // 222 - IRQ 206
  (uint32_t) noop,     // 223 - IRQ 207
  (uint32_t) noop,     // 224 - IRQ 208
  (uint32_t) noop,     // 225 - IRQ 209
  (uint32_t) noop,     // 226 - IRQ 210
  (uint32_t) noop,     // 227 - IRQ 211
  (uint32_t) noop,     // 228 - IRQ 212
  (uint32_t) noop,     // 229 - IRQ 213
  (uint32_t) noop,     // 230 - IRQ 214
  (uint32_t) noop,     // 231 - IRQ 215
  (uint32_t) noop,     // 232 - IRQ 216
  (uint32_t) noop,     // 233 - IRQ 217
  (uint32_t) noop,     // 234 - IRQ 218
  (uint32_t) noop,     // 235 - IRQ 219
  (uint32_t) noop,     // 236 - IRQ 220
  (uint32_t) noop,     // 237 - IRQ 221
  (uint32_t) noop,     // 238 - IRQ 222
  (uint32_t) noop,     // 239 - IRQ 223
  (uint32_t) noop,     // 240 - IRQ 224
  (uint32_t) noop,     // 241 - IRQ 225
  (uint32_t) noop,     // 242 - IRQ 226
  (uint32_t) noop,     // 243 - IRQ 227
  (uint32_t) noop,     // 244 - IRQ 228
  (uint32_t) noop,     // 245 - IRQ 229
  (uint32_t) noop,     // 246 - IRQ 230
  (uint32_t) noop,     // 247 - IRQ 231
  (uint32_t) noop,     // 248 - IRQ 232
  (uint32_t) noop,     // 249 - IRQ 233
  (uint32_t) noop,     // 250 - IRQ 234
  (uint32_t) noop,     // 251 - IRQ 235
  (uint32_t) noop,     // 252 - IRQ 236
  (uint32_t) noop,     // 253 - IRQ 237
  (uint32_t) noop,     // 254 - IRQ 238
  (uint32_t) noop,     // 255 - IRQ 239
};

// Implementations
void trap(void) { while(1); }
void noop(void) {}
void rsth(void) {
  init();
  main();
}

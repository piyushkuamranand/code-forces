<h2><a href="https://codeforces.com/contest/1082/problem/E" target="_blank" rel="noopener noreferrer">1082E — Increasing Frequency</a></h2>

| | |
|---|---|
| **Difficulty** | 2000 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1082E](https://codeforces.com/contest/1082/problem/E) |

## Topics
`binary search` `dp` `greedy`

---

## Problem Statement

<div class="header"><div class="title">E. Increasing Frequency</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>You are given array $$$a$$$ of length $$$n$$$. You can choose one segment $$$[l, r]$$$ ($$$1 \le l \le r \le n$$$) and integer value $$$k$$$ (positive, negative or even zero) and change $$$a_l, a_{l + 1}, \dots, a_r$$$ by $$$k$$$ each (i.e. $$$a_i := a_i + k$$$ for each $$$l \le i \le r$$$).</p><p>What is the maximum possible number of elements with value $$$c$$$ that can be obtained after one such operation?</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains two integers $$$n$$$ and $$$c$$$ ($$$1 \le n \le 5 \cdot 10^5$$$, $$$1 \le c \le 5 \cdot 10^5$$$) — the length of array and the value $$$c$$$ to obtain.</p><p>The second line contains $$$n$$$ integers $$$a_1, a_2, \dots, a_n$$$ ($$$1 \le a_i \le 5 \cdot 10^5$$$) — array $$$a$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>Print one integer — the maximum possible number of elements with value $$$c$$$ which can be obtained after performing operation described above.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0038578321670886684" id="id00017234689642817602" class="input-output-copier">Copy</div></div><pre id="id0038578321670886684">6 9
9 9 9 9 9 9
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0043439752633522166" id="id005004028482426301" class="input-output-copier">Copy</div></div><pre id="id0043439752633522166">6
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id005001735005241579" id="id00663885177833391" class="input-output-copier">Copy</div></div><pre id="id005001735005241579">3 2
6 2 6
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id005796867059659205" id="id005856626821577019" class="input-output-copier">Copy</div></div><pre id="id005796867059659205">2
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first example we can choose any segment and $$$k = 0$$$. The array will stay same.</p><p>In the second example we can choose segment $$$[1, 3]$$$ and $$$k = -4$$$. The array will become $$$[2, -2, 2]$$$.</p></div>
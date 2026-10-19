<h2><a href="https://codeforces.com/contest/1790/problem/E" target="_blank" rel="noopener noreferrer">1790E — Vlad and a Pair of Numbers</a></h2>

| | |
|---|---|
| **Difficulty** | 1400 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1790E](https://codeforces.com/contest/1790/problem/E) |

## Topics
`bitmasks` `constructive algorithms`

---

## Problem Statement

<div class="header"><div class="title">E. Vlad and a Pair of Numbers</div><div class="time-limit"><div class="property-title">time limit per test</div>1 second</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Vlad found two positive numbers $$$a$$$ and $$$b$$$ ($$$a,b \gt 0$$$). He discovered that $$$a \oplus b = \frac{a + b}{2}$$$, where $$$\oplus$$$ means the <a href="http://tiny.cc/xor_wiki_eng">bitwise exclusive OR</a> , and division is performed without rounding..</p><p>Since it is easier to remember one number than two, Vlad remembered only $$$a\oplus b$$$, let's denote this number as $$$x$$$. Help him find any suitable $$$a$$$ and $$$b$$$ or tell him that they do not exist.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line of the input data contains the single integer $$$t$$$ ($$$1 \le t \le 10^4$$$) — the number of test cases in the test. </p><p>Each test case is described by a single integer $$$x$$$ ($$$1 \le x \le 2^{29}$$$) — the number that Vlad remembered.</p></div><div class="output-specification"><div class="section-title">Output</div><p>Output $$$t$$$ lines, each of which is the answer to the corresponding test case. As the answer, output $$$a$$$ and $$$b$$$ ($$$0  \lt  a,b \le 2^{32}$$$), such that $$$x = a \oplus b = \frac{a + b}{2}$$$. If there are several answers, output any of them. If there are no matching pairs, output <span class="tex-font-style-tt">-1</span>.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0010094530061678686" id="id008643701547168053" class="input-output-copier">Copy</div></div><pre id="id0010094530061678686"><div class="test-example-line test-example-line-even test-example-line-0">6</div><div class="test-example-line test-example-line-odd test-example-line-1">2</div><div class="test-example-line test-example-line-even test-example-line-2">5</div><div class="test-example-line test-example-line-odd test-example-line-3">10</div><div class="test-example-line test-example-line-even test-example-line-4">6</div><div class="test-example-line test-example-line-odd test-example-line-5">18</div><div class="test-example-line test-example-line-even test-example-line-6">36</div></pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id001948579588248125" id="id009199187813433957" class="input-output-copier">Copy</div></div><pre id="id001948579588248125">3 1
-1
13 7
-1
25 11
50 22</pre></div></div></div>
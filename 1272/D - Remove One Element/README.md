<h2><a href="https://codeforces.com/contest/1272/problem/D" target="_blank" rel="noopener noreferrer">1272D — Remove One Element</a></h2>

| | |
|---|---|
| **Difficulty** | 1500 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1272D](https://codeforces.com/contest/1272/problem/D) |

## Topics
`brute force` `dp`

---

## Problem Statement

<div class="header"><div class="title">D. Remove One Element</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>You are given an array $$$a$$$ consisting of $$$n$$$ integers.</p><p>You can remove <span class="tex-font-style-bf">at most one</span> element from this array. Thus, the final length of the array is $$$n-1$$$ or $$$n$$$.</p><p>Your task is to calculate the maximum possible length of the <span class="tex-font-style-bf">strictly increasing</span> contiguous subarray of the remaining array.</p><p>Recall that the contiguous subarray $$$a$$$ with indices from $$$l$$$ to $$$r$$$ is $$$a[l \dots r] = a_l, a_{l + 1}, \dots, a_r$$$. The subarray $$$a[l \dots r]$$$ is called strictly increasing if $$$a_l  \lt  a_{l+1}  \lt  \dots  \lt  a_r$$$.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line of the input contains one integer $$$n$$$ ($$$2 \le n \le 2 \cdot 10^5$$$) — the number of elements in $$$a$$$.</p><p>The second line of the input contains $$$n$$$ integers $$$a_1, a_2, \dots, a_n$$$ ($$$1 \le a_i \le 10^9$$$), where $$$a_i$$$ is the $$$i$$$-th element of $$$a$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>Print one integer — the maximum possible length of the <span class="tex-font-style-bf">strictly increasing</span> contiguous subarray of the array $$$a$$$ after removing at most one element.</p></div><div class="sample-tests"><div class="section-title">Examples</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0016675993073522877" id="id0014770334988149791" class="input-output-copier">Copy</div></div><pre id="id0016675993073522877">5
1 2 5 3 4
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id006678802159186493" id="id00017735635397635785" class="input-output-copier">Copy</div></div><pre id="id006678802159186493">4
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id0003152532129415708" id="id007833671033715044" class="input-output-copier">Copy</div></div><pre id="id0003152532129415708">2
1 2
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id006892448389602628" id="id009806889792417143" class="input-output-copier">Copy</div></div><pre id="id006892448389602628">2
</pre></div><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id005829814747987659" id="id009570564058169312" class="input-output-copier">Copy</div></div><pre id="id005829814747987659">7
6 5 4 3 2 4 3
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id0018572430929927042" id="id0008101174796634925" class="input-output-copier">Copy</div></div><pre id="id0018572430929927042">2
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>In the first example, you can delete $$$a_3=5$$$. Then the resulting array will be equal to $$$[1, 2, 3, 4]$$$ and the length of its largest increasing subarray will be equal to $$$4$$$.</p></div>
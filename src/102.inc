<div class="question">
  <div class="title">
    Question
  </div>
  <div class="content">
    I would like the <var>TMemo</var> object to have a 250 line scroll
    buffer. In other words, when the 251st line is added, the first line is
    removed from the <var>TMemo</var> object. Is there a way to accomplish
    this without having to copy each string from index n to index n - 1 each
    time the 250th line is added?
  </div>
</div>

<p>
  You can use <var>TStrings</var>' <var>Delete</var> method and pass the index
  to it.
</p>

<div class="frame">
<!-- Highlighted Pascal code generated by DelphiDabbler PasH -->
<pre class="pas-source"><span class="pas-kwd">if</span><span class="pas-space"> </span><span class="pas-ident">memo1</span><span class="pas-sym">.</span><span class="pas-ident">Lines</span><span class="pas-sym">.</span><span class="pas-ident">Count</span><span class="pas-space"> </span><span class="pas-sym">=</span><span class="pas-space"> </span><span class="pas-num">251</span><span class="pas-space"> </span><span class="pas-kwd">then</span>
<span class="pas-space">  </span><span class="pas-ident">Memo1</span><span class="pas-sym">.</span><span class="pas-ident">lines</span><span class="pas-sym">.</span><span class="pas-ident">Delete</span><span class="pas-sym">(</span><span class="pas-num">0</span><span class="pas-sym">)</span><span class="pas-sym">;</span></pre>
</div>
<p>
    This function returns the size, in bytes, of the passed file:
</p>

<div class="frame">
<!-- Highlighted Pascal code generated by DelphiDabbler PasHi -->
<pre class="pas-source"><span class="pas-kwd">function</span><span class="pas-space"> </span><span class="pas-ident">TextfileSize</span><span class="pas-sym">(</span><span class="pas-kwd">const</span><span class="pas-space"> </span><span class="pas-kwd">name</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-kwd">string</span><span class="pas-sym">)</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">LongInt</span><span class="pas-sym">;</span><span class="pas-space"> </span>
<span class="pas-kwd">var</span>
<span class="pas-space">  </span><span class="pas-ident">SRec</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">TSearchRec</span><span class="pas-sym">;</span>
<span class="pas-kwd">begin</span>
<span class="pas-space">  </span><span class="pas-kwd">if</span><span class="pas-space"> </span><span class="pas-ident">FindFirst</span><span class="pas-sym">(</span><span class="pas-kwd">name</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">faAnyfile</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">SRec</span><span class="pas-sym">)</span><span class="pas-space"> </span><span class="pas-sym">=</span><span class="pas-space"> </span><span class="pas-num">0</span><span class="pas-space"> </span><span class="pas-kwd">then</span>
<span class="pas-space">  </span><span class="pas-kwd">begin</span>
<span class="pas-space">    </span><span class="pas-ident">Result</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">SRec</span><span class="pas-sym">.</span><span class="pas-ident">Size</span><span class="pas-sym">;</span>
<span class="pas-space">    </span><span class="pas-ident">Sysutils</span><span class="pas-sym">.</span><span class="pas-ident">FindClose</span><span class="pas-sym">(</span><span class="pas-ident">SRec</span><span class="pas-sym">)</span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-kwd">end</span>
<span class="pas-space">  </span><span class="pas-kwd">else</span>
<span class="pas-space">    </span><span class="pas-ident">Result</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-num">0</span><span class="pas-sym">;</span>
<span class="pas-kwd">end</span><span class="pas-sym">;</span></pre>
</div>
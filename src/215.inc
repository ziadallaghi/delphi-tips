<div class="frame">
<!-- Highlighted Pascal code generated by DelphiDabbler PasHi -->
<div class="pas-source">
<pre class="line"><span class="pas-kwd">var</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-ident">PPal</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">PLogPalette</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-ident">i</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">byte</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-kwd">begin</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-ident">GetMem</span><span class="pas-space"> </span><span class="pas-sym">(</span><span class="pas-ident">PPal</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">SizeOf</span><span class="pas-sym">(</span><span class="pas-ident">TLogPalette</span><span class="pas-sym">)</span><span class="pas-space"> </span><span class="pas-sym">+</span><span class="pas-space"> </span><span class="pas-num">255</span><span class="pas-space"> </span><span class="pas-sym">*</span><span class="pas-space"> </span><span class="pas-ident">SizeOf</span><span class="pas-sym">(</span><span class="pas-ident">TPaletteEntry</span><span class="pas-sym">)</span><span class="pas-sym">)</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-kwd">with</span><span class="pas-space"> </span><span class="pas-ident">PPal</span><span class="pas-sym">^</span><span class="pas-space"> </span><span class="pas-kwd">do</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-kwd">begin</span></pre>
<pre class="line"><span class="pas-space">    </span><span class="pas-ident">PalVersion</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-hex">$300</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-space">    </span><span class="pas-ident">PalNumEntries</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-num">256</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-space">    </span><span class="pas-preproc">{$R-}</span></pre>
<pre class="line"><span class="pas-space">    </span><span class="pas-kwd">for</span><span class="pas-space"> </span><span class="pas-ident">i</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-num">0</span><span class="pas-space"> </span><span class="pas-kwd">to</span><span class="pas-space"> </span><span class="pas-num">255</span><span class="pas-space"> </span><span class="pas-kwd">do</span></pre>
<pre class="line"><span class="pas-space">    </span><span class="pas-kwd">begin</span></pre>
<pre class="line"><span class="pas-space">      </span><span class="pas-ident">PalPalEntry</span><span class="pas-sym">[</span><span class="pas-ident">i</span><span class="pas-sym">]</span><span class="pas-sym">.</span><span class="pas-ident">peRed</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">i</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-space">      </span><span class="pas-ident">PalPalEntry</span><span class="pas-sym">[</span><span class="pas-ident">i</span><span class="pas-sym">]</span><span class="pas-sym">.</span><span class="pas-ident">peGreen</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">i</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-space">      </span><span class="pas-ident">PalPalEntry</span><span class="pas-sym">[</span><span class="pas-ident">i</span><span class="pas-sym">]</span><span class="pas-sym">.</span><span class="pas-ident">peBlue</span><span class="pas-space">  </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">i</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-space">      </span><span class="pas-ident">PalPalEntry</span><span class="pas-sym">[</span><span class="pas-ident">i</span><span class="pas-sym">]</span><span class="pas-sym">.</span><span class="pas-ident">peFlags</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-num">0</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-space">    </span><span class="pas-kwd">end</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-kwd">end</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-ident">Result</span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">CreatePalette</span><span class="pas-sym">(</span><span class="pas-ident">PPal</span><span class="pas-sym">^</span><span class="pas-sym">)</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-ident">FreeMem</span><span class="pas-space"> </span><span class="pas-sym">(</span><span class="pas-ident">PPal</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">SizeOf</span><span class="pas-sym">(</span><span class="pas-ident">TLogPalette</span><span class="pas-sym">)</span><span class="pas-space"> </span><span class="pas-sym">+</span><span class="pas-space"> </span><span class="pas-num">255</span><span class="pas-space"> </span><span class="pas-sym">*</span><span class="pas-space"> </span><span class="pas-ident">SizeOf</span><span class="pas-sym">(</span><span class="pas-ident">TPaletteEntry</span><span class="pas-sym">)</span><span class="pas-sym">)</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-kwd">end</span><span class="pas-sym">;</span></pre>
</div>
</div>
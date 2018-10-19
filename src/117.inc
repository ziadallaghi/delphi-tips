<div class="question">
  <div class="title">
    Question
  </div>
  <div class="content">
    I need to add a right-click capability to a popup menu. I created a
    component that inherits from <var>TPopupMenu</var>.
  </div>
</div>

<p>
  I suggest that you write the <var>OnMouseDown</var> event similar to the
  following:
</p>

<div class="frame">
<!-- Highlighted Pascal code generated by DelphiDabbler PasH -->
<pre class="pas-source"><span class="pas-comment">{ ... }</span>
<span class="pas-space">  </span><span class="pas-ident">TNewPopupMenu</span><span class="pas-space"> </span><span class="pas-sym">=</span><span class="pas-space"> </span><span class="pas-kwd">class</span><span class="pas-sym">(</span><span class="pas-ident">TPopupMenu</span><span class="pas-sym">)</span>
<span class="pas-space">  </span><span class="pas-kwd">private</span>
<span class="pas-space">    </span><span class="pas-ident">FOnMouseDown</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">TMouseEvent</span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-kwd">protected</span>
<span class="pas-space">    </span><span class="pas-kwd">procedure</span><span class="pas-space"> </span><span class="pas-ident">MouseDown</span><span class="pas-sym">(</span><span class="pas-ident">Button</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">TMouseButton</span><span class="pas-sym">;</span><span class="pas-space"> </span><span class="pas-ident">Shift</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">TShiftState</span><span class="pas-sym">;</span>
<span class="pas-space">      </span><span class="pas-ident">X</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">Y</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">Integer</span><span class="pas-sym">)</span><span class="pas-sym">;</span><span class="pas-space"> </span><span class="pas-kwd">dynamic</span><span class="pas-sym">;</span>
<span class="pas-space">    </span><span class="pas-kwd">procedure</span><span class="pas-space"> </span><span class="pas-ident">DoMouseDown</span><span class="pas-sym">(</span><span class="pas-kwd">var</span><span class="pas-space"> </span><span class="pas-kwd">Message</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">TWMMouse</span><span class="pas-sym">;</span>
<span class="pas-space">      </span><span class="pas-ident">Button</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">TMouseButton</span><span class="pas-sym">;</span><span class="pas-space"> </span><span class="pas-ident">Shift</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">TShiftState</span><span class="pas-sym">)</span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-kwd">published</span>
<span class="pas-space">    </span><span class="pas-kwd">property</span><span class="pas-space"> </span><span class="pas-ident">OnMouseDown</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">TMouseEvent</span>
<span class="pas-space">      </span><span class="pas-kwd">read</span><span class="pas-space"> </span><span class="pas-ident">FOnMouseDown</span><span class="pas-space"> </span><span class="pas-kwd">write</span><span class="pas-space"> </span><span class="pas-ident">FOnMouseDown</span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-kwd">end</span><span class="pas-sym">;</span>

<span class="pas-kwd">procedure</span><span class="pas-space"> </span><span class="pas-ident">TNewPopupMenu</span><span class="pas-sym">.</span><span class="pas-ident">MouseDown</span><span class="pas-sym">(</span><span class="pas-ident">Button</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">TMouseButton</span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-ident">Shift</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">TShiftState</span><span class="pas-sym">;</span><span class="pas-space"> </span><span class="pas-ident">X</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">Y</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">Integer</span><span class="pas-sym">)</span><span class="pas-sym">;</span>
<span class="pas-kwd">begin</span>
<span class="pas-space">  </span><span class="pas-kwd">if</span><span class="pas-space"> </span><span class="pas-ident">Assigned</span><span class="pas-sym">(</span><span class="pas-ident">FOnMouseDown</span><span class="pas-sym">)</span><span class="pas-space"> </span><span class="pas-kwd">then</span>
<span class="pas-space">    </span><span class="pas-ident">FOnMouseDown</span><span class="pas-sym">(</span><span class="pas-ident">Self</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">Button</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">Shift</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">X</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">Y</span><span class="pas-sym">)</span><span class="pas-sym">;</span>
<span class="pas-kwd">end</span><span class="pas-sym">;</span>

<span class="pas-kwd">procedure</span><span class="pas-space"> </span><span class="pas-ident">TNewPopupMenu</span><span class="pas-sym">.</span><span class="pas-ident">DoMouseDown</span><span class="pas-sym">(</span><span class="pas-kwd">var</span><span class="pas-space"> </span><span class="pas-kwd">Message</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">TWMMouse</span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-ident">Button</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">TMouseButton</span><span class="pas-sym">;</span><span class="pas-space"> </span><span class="pas-ident">Shift</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">TShiftState</span><span class="pas-sym">)</span><span class="pas-sym">;</span>
<span class="pas-kwd">begin</span>
<span class="pas-space">  </span><span class="pas-kwd">with</span><span class="pas-space"> </span><span class="pas-kwd">Message</span><span class="pas-space"> </span><span class="pas-kwd">do</span>
<span class="pas-space">    </span><span class="pas-ident">MouseDown</span><span class="pas-sym">(</span><span class="pas-ident">Button</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">KeysToShiftState</span><span class="pas-sym">(</span><span class="pas-ident">Keys</span><span class="pas-sym">)</span><span class="pas-space"> </span><span class="pas-sym">+</span><span class="pas-space"> </span><span class="pas-ident">Shift</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">XPos</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">YPos</span><span class="pas-sym">)</span><span class="pas-sym">;</span>
<span class="pas-kwd">end</span><span class="pas-sym">;</span></pre>
</div>
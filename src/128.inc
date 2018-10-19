<p>
  In most applications all (top level) menu items are aligned at the left
  side of the menu bar. I'm sure you have seen applications with at least one
  item aligned on the right side. In most cases this was the &quot;Help&quot;
  menu item.
</p>

<ol>
  <li>
    Add a TMainMenu component to a form (Form1)
  </li>
  <li>
    Add several (top level) menu items (with sub items)
  </li>
  <li>
    Have a menu item named &quot;HelpMenuItem&quot;
  </li>
  <li>
    Use the code below in the form's <var>OnCreate</var> event.
  </li>
</ol>

<div class="frame">
<!-- Highlighted Pascal code generated by DelphiDabbler PasH -->
<pre class="pas-source"><span class="pas-kwd">procedure</span><span class="pas-space"> </span><span class="pas-ident">TForm1</span><span class="pas-sym">.</span><span class="pas-ident">FormCreate</span><span class="pas-sym">(</span><span class="pas-ident">Sender</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">TObject</span><span class="pas-sym">)</span><span class="pas-space"> </span><span class="pas-sym">;</span>
<span class="pas-kwd">var</span>
<span class="pas-space">  </span><span class="pas-ident">mii</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">TMenuItemInfo</span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-ident">MainMenu</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">hMenu</span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-ident">Buffer</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-kwd">array</span><span class="pas-sym">[</span><span class="pas-num">0</span><span class="pas-sym">..</span><span class="pas-num">79</span><span class="pas-sym">]</span><span class="pas-space"> </span><span class="pas-kwd">of</span><span class="pas-space"> </span><span class="pas-ident">Char</span><span class="pas-sym">;</span>
<span class="pas-kwd">begin</span>
<span class="pas-space">  </span><span class="pas-ident">MainMenu</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">Self</span><span class="pas-sym">.</span><span class="pas-ident">Menu</span><span class="pas-sym">.</span><span class="pas-ident">Handle</span><span class="pas-sym">;</span>

<span class="pas-space">  </span><span class="pas-comment">//GET Help Menu Item Info</span>
<span class="pas-space">  </span><span class="pas-ident">mii</span><span class="pas-sym">.</span><span class="pas-ident">cbSize</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">SizeOf</span><span class="pas-sym">(</span><span class="pas-ident">mii</span><span class="pas-sym">)</span><span class="pas-space"> </span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-ident">mii</span><span class="pas-sym">.</span><span class="pas-ident">fMask</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">MIIM_TYPE</span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-ident">mii</span><span class="pas-sym">.</span><span class="pas-ident">dwTypeData</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">Buffer</span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-ident">mii</span><span class="pas-sym">.</span><span class="pas-ident">cch</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">SizeOf</span><span class="pas-sym">(</span><span class="pas-ident">Buffer</span><span class="pas-sym">)</span><span class="pas-space"> </span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-ident">GetMenuItemInfo</span><span class="pas-sym">(</span><span class="pas-ident">MainMenu</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">HelpMenuItem</span><span class="pas-sym">.</span><span class="pas-ident">Command</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">false</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">mii</span><span class="pas-sym">)</span><span class="pas-space"> </span><span class="pas-sym">;</span>

<span class="pas-space">  </span><span class="pas-comment">//SET Help Menu Item Info</span>
<span class="pas-space">  </span><span class="pas-ident">mii</span><span class="pas-sym">.</span><span class="pas-ident">fType</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">mii</span><span class="pas-sym">.</span><span class="pas-ident">fType</span><span class="pas-space"> </span><span class="pas-kwd">or</span><span class="pas-space"> </span><span class="pas-ident">MFT_RIGHTJUSTIFY</span><span class="pas-sym">;</span>
<span class="pas-space">  </span><span class="pas-ident">SetMenuItemInfo</span><span class="pas-sym">(</span><span class="pas-ident">MainMenu</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">HelpMenuItem</span><span class="pas-sym">.</span><span class="pas-ident">Command</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">false</span><span class="pas-sym">,</span><span class="pas-space"> </span><span class="pas-ident">mii</span><span class="pas-sym">)</span><span class="pas-space"> </span><span class="pas-sym">;</span>
<span class="pas-kwd">end</span><span class="pas-sym">;</span></pre>
</div>
<p>
  Dialog windows you use to display critical information to the user are, in
  most cases, displayed modally. A modal form is one where the application can't
  continue to run until the modal (information) form is closed. Delphi's
  <var>ShowMessage</var>, <var>InputBox</var> and <var>MessageDlg</var>, for
  example, display a modal form to the user waiting for some action. Your custom
  dialogs are displayed using the <var>ShowModal</var> method of a form. To
  emphasize the importance of a modal form and the information it presents, you
  could gray out the main form of the application when the modal form is
  activated. Here's how to add a dim-out effect to your main form when modal
  forms are waiting for the user input.
</p>

<p>
  Have a Main Form of your application Add a new form to the project. This will
  be the &quot;dimmer&quot; form. Drop the <var>TApplicationEvents</var>
  component on the main form. Handle the <var>OnModalBegin</var> and
  <var>OnModalEnd</var> events. The <var>TDimmerForm</var> is created at
  application startup - and since it is not the main form, it will not be
  displayed initially. The <var>Display</var> procedure aligns the dimmer form
  above the main form and gets displayed before any modal form is shown. This
  happens in the <var>TApplicationEvent</var>'s <var>OnModalBegin</var> event.
  <var>OnModalEnd</var> ensures that dimmer form is hidden until needed next
  time.
</p>

<div class ="frame">
<!-- Highlighted Pascal code generated by DelphiDabbler PasHi -->
<div class="pas-source">
<pre class="line"><span class="pas-kwd">procedure</span><span class="pas-space"> </span><span class="pas-ident">TDimmerForm</span><span class="pas-sym">.</span><span class="pas-ident">FormCreate</span><span class="pas-sym">(</span><span class="pas-ident">Sender</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">TObject</span><span class="pas-sym">)</span><span class="pas-space"> </span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-kwd">begin</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-ident">AlphaBlend</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">true</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-ident">AlphaBlendValue</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-num">128</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-ident">BorderStyle</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">bsNone</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-kwd">end</span><span class="pas-sym">;</span></pre>
</div>
</div>

<p>
  The above is the <var>OnCreate</var> event handler for the dimmer form. By
  using the <var>AlphaBlend</var> property and the <var>AlphaBlendValue</var>
  you can make the form translucent. As it will be displayed over the main form,
  we want it to create the dim-out effect. <var>BorderStyle</var> ensures this
  form has no border, no caption bar, no title buttons. The <var>Display</var>
  procedure aligns the dimmer form above the main form:
</p>

<div class="frame">
<!-- Highlighted Pascal code generated by DelphiDabbler PasHi -->
<div class="pas-source">
<pre class="line"><span class="pas-kwd">procedure</span><span class="pas-space"> </span><span class="pas-ident">TDimmerForm</span><span class="pas-sym">.</span><span class="pas-ident">Display</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-kwd">begin</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-kwd">with</span><span class="pas-space"> </span><span class="pas-ident">Self</span><span class="pas-space"> </span><span class="pas-kwd">do</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-kwd">begin</span></pre>
<pre class="line"><span class="pas-space">    </span><span class="pas-ident">Left</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">MainForm</span><span class="pas-sym">.</span><span class="pas-ident">Left</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-space">    </span><span class="pas-ident">Top</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">MainForm</span><span class="pas-sym">.</span><span class="pas-ident">Top</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-space">    </span><span class="pas-ident">Width</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">MainForm</span><span class="pas-sym">.</span><span class="pas-ident">Width</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-space">    </span><span class="pas-ident">Height</span><span class="pas-space"> </span><span class="pas-sym">:=</span><span class="pas-space"> </span><span class="pas-ident">MainForm</span><span class="pas-sym">.</span><span class="pas-ident">Height</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-space">    </span><span class="pas-ident">Show</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-kwd">end</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-kwd">end</span><span class="pas-sym">;</span></pre>
</div>
</div>

<p>
  Finally, handle the </var>OnModalBegin</var> and <var>OnModalEnd</var> events
  of the <var>TApplicationEvents</var> component on the main form:
</p>

<div class="frame">
<!-- Highlighted Pascal code generated by DelphiDabbler PasHi -->
<div class="pas-source">
<pre class="line"><span class="pas-comment">//TApplicationEvents OnModalBegin</span></pre>
<pre class="line"><span class="pas-kwd">procedure</span><span class="pas-space"> </span><span class="pas-ident">TMainForm</span><span class="pas-sym">.</span><span class="pas-ident">ApplicationEvents1ModalBegin</span><span class="pas-sym">(</span><span class="pas-ident">Sender</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">TObject</span><span class="pas-sym">)</span><span class="pas-space"> </span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-kwd">begin</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-ident">DimmerForm</span><span class="pas-sym">.</span><span class="pas-ident">Display</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-kwd">end</span><span class="pas-sym">;</span></pre>
<pre class="line"> </pre>
<pre class="line"><span class="pas-comment">//TApplicationEvents OnModalEnd</span></pre>
<pre class="line"><span class="pas-kwd">procedure</span><span class="pas-space"> </span><span class="pas-ident">TMainForm</span><span class="pas-sym">.</span><span class="pas-ident">ApplicationEvents1ModalEnd</span><span class="pas-sym">(</span><span class="pas-ident">Sender</span><span class="pas-sym">:</span><span class="pas-space"> </span><span class="pas-ident">TObject</span><span class="pas-sym">)</span><span class="pas-space"> </span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-kwd">begin</span></pre>
<pre class="line"><span class="pas-space">  </span><span class="pas-ident">DimmerForm</span><span class="pas-sym">.</span><span class="pas-ident">Hide</span><span class="pas-sym">;</span></pre>
<pre class="line"><span class="pas-kwd">end</span><span class="pas-sym">;</span></pre>
</div>
</div>

<p>
  That's it!
</p>

<p>
  In MDI (multiple document interface) Delphi applications, more than one form
  can be opened within a single parent window - main form. MDI application are
  ideal candidates for the dimmer form :)
</p>
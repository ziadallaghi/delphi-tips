<p>
  There is really no way to set the standard hint window to be always visible.
  The trick is to set the <var>HintHidePause</var> to a large value.
  minutes should almost always be enough. The hint window is shown only when
  the user moves the mouse over a component and the keyboard is inactive. Not
  many users keep the cursor over a control longer than 10 minutes...:) The
  default value is 2500 miliseconds (2.5 seconds).
</p>

<div class="frame">
<!-- Highlighted Pascal code generated by DelphiDabbler PasH -->
<pre class="pas-source">Application.HintHidePause := <span class="pas-num">600000</span>;</pre>
</div>
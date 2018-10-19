<p>
  Windows messaging is an easy way for processes to communicate. Below, you
  will find an example of sending such messages, as well as an example message
  handler to receive them.
</p>

<p>
  Please keep in mind that there is no guarantee that your process will
  receive this message. Or, it may receive it instantaneously. I recommend
  sending some sort of ACK response back to the originating app so I knows it
  was received properly.
</p>

<h2>
  Sender
</h2>

<div class="frame">
<!-- Highlighted Pascal code generated by DelphiDabbler PasH -->
<pre class="pas-source"><span class="pas-comment">// wmCopyData</span>
<span class="pas-comment">// Allows inter-process communications via Windows WM_COPYDATA messaging.</span>
<span class="pas-kwd">procedure</span> wmCopyData(WndClass:PChar;WndTitle:PChar;Msg:<span class="pas-kwd">String</span>);
<span class="pas-kwd">var</span>
  hWnd  : THandle         <span class="pas-comment">// Handle to target window to receive message</span>
  cds   : CopyDataStruct; <span class="pas-comment">// Structure to package the outbound message</span>
<span class="pas-kwd">begin</span>
  <span class="pas-comment">// Find target window</span>
  hWnd := FindWindow(PChar(WndClass), PChar(WndTitle));
  <span class="pas-kwd">try</span>
    cds.dwData := <span class="pas-num">0</span>
    cds.cbData := Length(Msg);   <span class="pas-comment">// Length of message</span>
    cds.lpData := PChar(Msg);    <span class="pas-comment">// Actual message</span>
    <span class="pas-comment">// The following function is not necessary for this to work</span>
    SetForegroundWindow(hWnd);   <span class="pas-comment">// Pulls target window up top</span>
    SendMessage(hWnd, wm_CopyData, <span class="pas-num">0</span>, Integer(@cds));
send the <span class="pas-kwd">message</span>
  <span class="pas-kwd">finally</span>
    CloseHandle(hWnd)            <span class="pas-comment">// Close handle to target</span>
  <span class="pas-kwd">end</span>;
<span class="pas-kwd">end</span>;</pre>
</div>

<p>
  A typical call to this procedure would be:
</p>

<div class="frame">
<!-- Highlighted Pascal code generated by DelphiDabbler PasH -->
<pre class="pas-source">wmCopyData(<span class="pas-str">'NOTEPAD'</span>,<span class="pas-str">'Untitled - Notepad'</span>,<span class="pas-str">'Test Message'</span>);</pre>
</div>

<p>
  Keep in mind that <em>Notepad</em> does not have a handler to receive
  messages sent via <var>WM_COPYDATA</var>.
</p>

<p>
  Also, it is not necessary to use both the Class name and Window title text,
  one is sufficient. However, if you have multiple copies open, it will go to
  the first one it finds.
</p>


<h2>
  Receiver
</h2>

<div class="frame">
<!-- Highlighted Pascal code generated by DelphiDabbler PasH -->
<pre class="pas-source"><span class="pas-comment">// Add a custom message handler so our app gets notified upon receipt</span>
<span class="pas-kwd">private</span>
  <span class="pas-kwd">procedure</span> WMGetData(<span class="pas-kwd">var</span> Msg: TWMCopyData); <span class="pas-kwd">message</span> WM_COPYDATA;

<span class="pas-comment">// wmGetData</span>
<span class="pas-comment">// Receives inbound messages - Callback function</span>
<span class="pas-comment">// Called from message handler</span>
<span class="pas-kwd">procedure</span> TForm1.wmGetData(<span class="pas-kwd">var</span> Msg: TWMCopyData);
<span class="pas-kwd">var</span>
  sText: <span class="pas-kwd">array</span>[<span class="pas-num">0</span>..<span class="pas-num">255</span>] <span class="pas-kwd">of</span> Char;  <span class="pas-comment">// Create an array to store message in</span>
<span class="pas-kwd">begin</span>
  <span class="pas-comment">// Cast inbound data structure into a character array</span>
  StrLCopy(sText, Msg.CopyDataStruct.lpData, Msg.CopyDataStruct.cbData);
  Edit1.Text := sText;
<span class="pas-kwd">end</span>;</pre>
</div>
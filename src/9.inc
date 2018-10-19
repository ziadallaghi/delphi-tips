<p>
  Here's an example of how to write a function that'll return a file's last
  access time (not to be confused with the last modified time).
</p>

<div class="frame">
<!-- Highlighted Pascal code generated by DelphiDabbler PasH -->
<pre class="pas-source"><span class="pas-kwd">function</span> GetFileLastAccessTime(sFileName: <span class="pas-kwd">string</span>): TDateTime;
<span class="pas-kwd">var</span>
  ffd : TWin32FindData;
  dft : DWord;
  lft : TFileTime;
  h   : THandle;
<span class="pas-kwd">begin</span>
  <span class="pas-comment">// get file information</span>
  h := Windows.FindFirstFile(PChar(sFileName), ffd);
  <span class="pas-kwd">if</span> INVALID_HANDLE_VALUE &lt;&gt; h <span class="pas-kwd">then</span>
  <span class="pas-kwd">begin</span>
    <span class="pas-comment">// we're looking for just one file, so close our &quot;find&quot;</span>
    Windows.FindClose(h);

    <span class="pas-comment">// convert the FILETIME to local FILETIME</span>
    FileTimeToLocalFileTime(ffd.ftLastAccessTime, lft);

    <span class="pas-comment">// convert FILETIME to DOS time</span>
    FileTimeToDosDateTime(lft, LongRec(dft).Hi, LongRec(dft).Lo);

    <span class="pas-comment">// finally, convert DOS time to TDateTime for use in Delphi's</span>
    <span class="pas-comment">// native date/time functions</span>
    Result := FileDateToDateTime(dft);
  <span class="pas-kwd">end</span>;
<span class="pas-kwd">end</span>;</pre>
</div>

<p>
  <var>GetFileLastAccessTime()</var> will return a given file's last access
  time as a Delphi <var>TDateTime</var> type which you can convert to a string
  by using the <var>DateTimeToStr()</var> function. For example:
</p>

<div class="frame">
<!-- Highlighted Pascal code generated by DelphiDabbler PasH -->
<pre class="pas-source">MessageDlg(
    <span class="pas-str">'c:\config.sys was last accessed on '</span>
    + DateTimeToStr(GetFileLastAccessTime(<span class="pas-str">'c:\config.sys'</span>)),
    mtInformation, [mbOk], <span class="pas-num">0</span>
);</pre>
</div>
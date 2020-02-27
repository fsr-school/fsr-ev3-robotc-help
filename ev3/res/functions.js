function getURLParameter(name) {
    return decodeURI(
        (RegExp(name + '=' + '(.+?)(&|$)').exec(location.search)||[,null])[1]
    );
}

function insertThirtPartyMenus(post_func) {
	var moduleToParentId = {
		'Action':'ActionBlocks',
		'FlowControl':'FlowBlocks',
		'Sensor':'SensorBlocks',
		'DataOperations':'DataBlock',
		'Advanced':'AdvancedBlocks'
	};

	$.get('/allblocks.x3wsc', null, function(xml) {
		$(xml).find('Block').each(function(){
			var module = $(this).attr('Module');

			if (module != 'LEGO') {
				var name = $(this).attr('Name');
				var displayName = $(this).attr('DisplayName');
				var menuParent = $(this).attr('MenuParent');
	
				var parent = $('#' + moduleToParentId[menuParent]);
				var path = 'blocks/' + module + '/' + name + '.html';
				
				parent.find('.children').append('<div id="'+name+'" class="level3 leaf"><a href="page.html?Path='+encodeURIComponent(path)+'">'+displayName+'</a></div>');
			}			
		});
		
		if (post_func) {
			post_func();
		}
	}, 'xml');
}




/**
 * url参数转json对象
 *
 * @param {string} [url=window.location.href] url字符串，默认为当前页面路径
 * @return {object} 参数json对象
 *
 */
function urlParamToJson(url) {
	!url && (url=window.location.href);
	var i = url.indexOf('?');
	var j = url.indexOf('#');
	j = j>-1?j:undefined;
	var pathname = i>-1 ? url.slice(0, i) : url.slice(0, j);
	var search = i>-1 ? url.slice(i+1, j) : '';
	var hash = j>-1 ? url.slice(j+1) : '';
	var o = {};
	o['?'] = pathname;
	o['#'] = hash;
	o['&'] = search;
	if( search.length>0 ) {
		var ary = search.split('&');
		for (var i = 0; i < ary.length; i++) {
			var item = ary[i];
			var sary = item.split('=');
			var attr = decodeURI(sary[0]);
			var value = decodeURI(sary[1]);
			o[attr] = value;
		}
	}
	return o;
}

--[[
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	   audio_manager.lua
@ author:	   Connor
@ version:	   1.0.0
@ date:		   2018-03-03
@ description: audio manager.
@ others:
@ history:
1.date:
author:
modification:
--]]

local M = {}

M.EffectMusicFiles = {
	{ "tiao1.mp3", "tiao2.mp3", "tiao3.mp3", "tiao4.mp3", "tiao5.mp3", "tiao6.mp3", "tiao7.mp3", "tiao8.mp3", "tiao9.mp3" },
	{ "wan1.mp3", "wan2.mp3", "wan3.mp3", "wan4.mp3", "wan5.mp3", "wan6.mp3", "wan7.mp3", "wan8.mp3", "wan9.mp3" },
	{ "tong1.mp3", "tong2.mp3", "tong3.mp3", "tong4.mp3", "tong5.mp3", "tong6.mp3", "tong7.mp3", "tong8.mp3", "tong9.mp3" },
	{ "dongfeng.mp3", "nanfeng.mp3", "xifeng.mp3", "beifeng.mp3", "facai.mp3", "hongzhong.mp3", "baiban.mp3" },
	{ "buhua.mp3" },
	{ "chi.mp3", "peng.mp3", "gang.mp3", "ting.mp3", "hu.mp3", "zimo.mp3", "guo.mp3" }
}

M.CommonTouchEffectMusicFile = "audio/effect/common/btn_click.mp3"

M.HallBGMMusicFile = "audio/music/hall_bgm.mp3"

M.PlayCardEffectMusicTypes = 
{
	WOMEN = 0,
	MAN   = 1
}

M.Operations = 
{
    BUHUA = 41,
	CHI   = 42,
	PENG  = 43,
	GANG  = 44,
	TING  = 45,
	HU    = 46,
	ZIMO  = 47,
	GUO   = 48
}

function M.playHallBGM()
	if not M.hall_bgm_audio_id_ then
		M.hall_bgm_audio_id_ = ccexp.AudioEngine:play2d(M.HallBGMMusicFile, true)
	else
		local state = ccexp.AudioEngine:getState(M.hall_bgm_audio_id_)
		if 0 == state then -- INITIALIZING
			return
		elseif 1 == state then -- PLAYING
			return
		elseif 2 == state then -- PAUSED
			ccexp.AudioEngine:resume(M.hall_bgm_audio_id_)
		end
	end
end

function M.stopHallBGM()
	if M.hall_bgm_audio_id_ then
		ccexp.AudioEngine:stop(M.hall_bgm_audio_id_)
		M.hall_bgm_audio_id_ = nil
	end
end

function M.playCommonTouchEffectMusic()
	ccexp.AudioEngine:play2d(M.CommonTouchEffectMusicFile)
end

function M.playEffectMusicForPlayCard(card_value)
	if M.cur_play_effect_music_type_ == M.PlayCardEffectMusicTypes.MAN then
		M.playEffectMusicForManPlayCard(card_value)
	else
		M.playEffectMusicForWomenPlayCard(card_value)
	end
end

function M.playEffectMusicForWomenPlayCard(card_value)
	if false == M.effect_music_enabled_ then
		print("[AudioManager:playEffectMusicForWomenPlayCard] false == M.effect_music_enabled_, return")
		return
	end

	local file = M.getEffectMusicFile(card_value)
	if file then
		ccexp.AudioEngine:play2d("audio/effect/play_game/w/" .. file)
	else
		print("[AudioManager:playEffectMusicForWomenPlayCard] audio file not found, card_value :", card_value)
	end
end

function M.playEffectMusicForManPlayCard(card_value)
	if false == M.effect_music_enabled_ then
		print("[AudioManager:playEffectMusicForManPlayCard] false == M.effect_music_enabled_, return")
		return
	end

	local file = M.getEffectMusicFile(card_value)
	if file then
		ccexp.AudioEngine:play2d("audio/effect/play_game/m/" .. file)
	else
		print("[AudioManager:playEffectMusicForWomenPlayCard] audio file not found, card_value :", card_value)
	end
end

function M.enableEffectMusic()
	M.effect_music_enabled_ = true
end

function M.disableEffectMusic()
	M.effect_music_enabled_ = false
end

function M.setPlayCardEffectMusicType(type)
	M.cur_play_effect_music_type_ = type
end

------------------------------------ private ------------------------------------

function M.init()

end

function M.getEffectMusicFile(card_value)
	if card_value <= 8 then
		return M.EffectMusicFiles[1][card_value + 1]
	elseif card_value <= 17 then
		return M.EffectMusicFiles[2][card_value - 8]
	elseif card_value <= 26 then
		return M.EffectMusicFiles[3][card_value - 17]
	elseif card_value <= 33 then
		return M.EffectMusicFiles[4][card_value - 26]
	elseif card_value <= 41 then
		return M.EffectMusicFiles[5][1]
	elseif card_value <= 48 then
		return M.EffectMusicFiles[6][card_value - 41]
	end
	return nil
end

--------------------------------- end private -----------------------------------

return M
// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: game_start_msg_protocol.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "game_start_msg_protocol.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace gamer {
namespace protocol {

namespace {

const ::google::protobuf::Descriptor* GameStartMsgProtocol_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  GameStartMsgProtocol_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_game_5fstart_5fmsg_5fprotocol_2eproto() {
  protobuf_AddDesc_game_5fstart_5fmsg_5fprotocol_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "game_start_msg_protocol.proto");
  GOOGLE_CHECK(file != NULL);
  GameStartMsgProtocol_descriptor_ = file->message_type(0);
  static const int GameStartMsgProtocol_offsets_[11] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameStartMsgProtocol, room_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameStartMsgProtocol, room_owner_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameStartMsgProtocol, players_num_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameStartMsgProtocol, cur_round_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameStartMsgProtocol, total_round_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameStartMsgProtocol, remain_cards_num_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameStartMsgProtocol, banker_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameStartMsgProtocol, banker_is_same_time_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameStartMsgProtocol, cur_acting_player_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameStartMsgProtocol, cur_action_id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameStartMsgProtocol, player_cards_),
  };
  GameStartMsgProtocol_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      GameStartMsgProtocol_descriptor_,
      GameStartMsgProtocol::default_instance_,
      GameStartMsgProtocol_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameStartMsgProtocol, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(GameStartMsgProtocol, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(GameStartMsgProtocol));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_game_5fstart_5fmsg_5fprotocol_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    GameStartMsgProtocol_descriptor_, &GameStartMsgProtocol::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_game_5fstart_5fmsg_5fprotocol_2eproto() {
  delete GameStartMsgProtocol::default_instance_;
  delete GameStartMsgProtocol_reflection_;
}

void protobuf_AddDesc_game_5fstart_5fmsg_5fprotocol_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::gamer::protocol::protobuf_AddDesc_player_5fcards_5fmsg_5fprotocol_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\035game_start_msg_protocol.proto\022\016gamer.p"
    "rotocol\032\037player_cards_msg_protocol.proto"
    "\"\270\002\n\024GameStartMsgProtocol\022\017\n\007room_id\030\001 \002"
    "(\005\022\025\n\rroom_owner_id\030\002 \002(\005\022\023\n\013players_num"
    "\030\003 \001(\005\022\021\n\tcur_round\030\004 \001(\005\022\023\n\013total_round"
    "\030\005 \001(\005\022\030\n\020remain_cards_num\030\006 \001(\005\022\021\n\tbank"
    "er_id\030\007 \001(\005\022\033\n\023banker_is_same_time\030\010 \001(\005"
    "\022\034\n\024cur_acting_player_id\030\t \001(\005\022\025\n\rcur_ac"
    "tion_id\030\n \001(\005\022<\n\014player_cards\030\013 \003(\0132&.ga"
    "mer.protocol.PlayerCardsMsgProtocol", 395);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "game_start_msg_protocol.proto", &protobuf_RegisterTypes);
  GameStartMsgProtocol::default_instance_ = new GameStartMsgProtocol();
  GameStartMsgProtocol::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_game_5fstart_5fmsg_5fprotocol_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_game_5fstart_5fmsg_5fprotocol_2eproto {
  StaticDescriptorInitializer_game_5fstart_5fmsg_5fprotocol_2eproto() {
    protobuf_AddDesc_game_5fstart_5fmsg_5fprotocol_2eproto();
  }
} static_descriptor_initializer_game_5fstart_5fmsg_5fprotocol_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int GameStartMsgProtocol::kRoomIdFieldNumber;
const int GameStartMsgProtocol::kRoomOwnerIdFieldNumber;
const int GameStartMsgProtocol::kPlayersNumFieldNumber;
const int GameStartMsgProtocol::kCurRoundFieldNumber;
const int GameStartMsgProtocol::kTotalRoundFieldNumber;
const int GameStartMsgProtocol::kRemainCardsNumFieldNumber;
const int GameStartMsgProtocol::kBankerIdFieldNumber;
const int GameStartMsgProtocol::kBankerIsSameTimeFieldNumber;
const int GameStartMsgProtocol::kCurActingPlayerIdFieldNumber;
const int GameStartMsgProtocol::kCurActionIdFieldNumber;
const int GameStartMsgProtocol::kPlayerCardsFieldNumber;
#endif  // !_MSC_VER

GameStartMsgProtocol::GameStartMsgProtocol()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:gamer.protocol.GameStartMsgProtocol)
}

void GameStartMsgProtocol::InitAsDefaultInstance() {
}

GameStartMsgProtocol::GameStartMsgProtocol(const GameStartMsgProtocol& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:gamer.protocol.GameStartMsgProtocol)
}

void GameStartMsgProtocol::SharedCtor() {
  _cached_size_ = 0;
  room_id_ = 0;
  room_owner_id_ = 0;
  players_num_ = 0;
  cur_round_ = 0;
  total_round_ = 0;
  remain_cards_num_ = 0;
  banker_id_ = 0;
  banker_is_same_time_ = 0;
  cur_acting_player_id_ = 0;
  cur_action_id_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

GameStartMsgProtocol::~GameStartMsgProtocol() {
  // @@protoc_insertion_point(destructor:gamer.protocol.GameStartMsgProtocol)
  SharedDtor();
}

void GameStartMsgProtocol::SharedDtor() {
  if (this != default_instance_) {
  }
}

void GameStartMsgProtocol::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* GameStartMsgProtocol::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return GameStartMsgProtocol_descriptor_;
}

const GameStartMsgProtocol& GameStartMsgProtocol::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_game_5fstart_5fmsg_5fprotocol_2eproto();
  return *default_instance_;
}

GameStartMsgProtocol* GameStartMsgProtocol::default_instance_ = NULL;

GameStartMsgProtocol* GameStartMsgProtocol::New() const {
  return new GameStartMsgProtocol;
}

void GameStartMsgProtocol::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<GameStartMsgProtocol*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 255) {
    ZR_(room_id_, banker_is_same_time_);
  }
  ZR_(cur_acting_player_id_, cur_action_id_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  player_cards_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool GameStartMsgProtocol::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:gamer.protocol.GameStartMsgProtocol)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 room_id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &room_id_)));
          set_has_room_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_room_owner_id;
        break;
      }

      // required int32 room_owner_id = 2;
      case 2: {
        if (tag == 16) {
         parse_room_owner_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &room_owner_id_)));
          set_has_room_owner_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_players_num;
        break;
      }

      // optional int32 players_num = 3;
      case 3: {
        if (tag == 24) {
         parse_players_num:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &players_num_)));
          set_has_players_num();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_cur_round;
        break;
      }

      // optional int32 cur_round = 4;
      case 4: {
        if (tag == 32) {
         parse_cur_round:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &cur_round_)));
          set_has_cur_round();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_total_round;
        break;
      }

      // optional int32 total_round = 5;
      case 5: {
        if (tag == 40) {
         parse_total_round:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &total_round_)));
          set_has_total_round();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_remain_cards_num;
        break;
      }

      // optional int32 remain_cards_num = 6;
      case 6: {
        if (tag == 48) {
         parse_remain_cards_num:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &remain_cards_num_)));
          set_has_remain_cards_num();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(56)) goto parse_banker_id;
        break;
      }

      // optional int32 banker_id = 7;
      case 7: {
        if (tag == 56) {
         parse_banker_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &banker_id_)));
          set_has_banker_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(64)) goto parse_banker_is_same_time;
        break;
      }

      // optional int32 banker_is_same_time = 8;
      case 8: {
        if (tag == 64) {
         parse_banker_is_same_time:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &banker_is_same_time_)));
          set_has_banker_is_same_time();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(72)) goto parse_cur_acting_player_id;
        break;
      }

      // optional int32 cur_acting_player_id = 9;
      case 9: {
        if (tag == 72) {
         parse_cur_acting_player_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &cur_acting_player_id_)));
          set_has_cur_acting_player_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(80)) goto parse_cur_action_id;
        break;
      }

      // optional int32 cur_action_id = 10;
      case 10: {
        if (tag == 80) {
         parse_cur_action_id:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &cur_action_id_)));
          set_has_cur_action_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(90)) goto parse_player_cards;
        break;
      }

      // repeated .gamer.protocol.PlayerCardsMsgProtocol player_cards = 11;
      case 11: {
        if (tag == 90) {
         parse_player_cards:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_player_cards()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(90)) goto parse_player_cards;
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:gamer.protocol.GameStartMsgProtocol)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:gamer.protocol.GameStartMsgProtocol)
  return false;
#undef DO_
}

void GameStartMsgProtocol::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:gamer.protocol.GameStartMsgProtocol)
  // required int32 room_id = 1;
  if (has_room_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->room_id(), output);
  }

  // required int32 room_owner_id = 2;
  if (has_room_owner_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->room_owner_id(), output);
  }

  // optional int32 players_num = 3;
  if (has_players_num()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->players_num(), output);
  }

  // optional int32 cur_round = 4;
  if (has_cur_round()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->cur_round(), output);
  }

  // optional int32 total_round = 5;
  if (has_total_round()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(5, this->total_round(), output);
  }

  // optional int32 remain_cards_num = 6;
  if (has_remain_cards_num()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(6, this->remain_cards_num(), output);
  }

  // optional int32 banker_id = 7;
  if (has_banker_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(7, this->banker_id(), output);
  }

  // optional int32 banker_is_same_time = 8;
  if (has_banker_is_same_time()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(8, this->banker_is_same_time(), output);
  }

  // optional int32 cur_acting_player_id = 9;
  if (has_cur_acting_player_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(9, this->cur_acting_player_id(), output);
  }

  // optional int32 cur_action_id = 10;
  if (has_cur_action_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(10, this->cur_action_id(), output);
  }

  // repeated .gamer.protocol.PlayerCardsMsgProtocol player_cards = 11;
  for (int i = 0; i < this->player_cards_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      11, this->player_cards(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:gamer.protocol.GameStartMsgProtocol)
}

::google::protobuf::uint8* GameStartMsgProtocol::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:gamer.protocol.GameStartMsgProtocol)
  // required int32 room_id = 1;
  if (has_room_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->room_id(), target);
  }

  // required int32 room_owner_id = 2;
  if (has_room_owner_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->room_owner_id(), target);
  }

  // optional int32 players_num = 3;
  if (has_players_num()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->players_num(), target);
  }

  // optional int32 cur_round = 4;
  if (has_cur_round()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->cur_round(), target);
  }

  // optional int32 total_round = 5;
  if (has_total_round()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, this->total_round(), target);
  }

  // optional int32 remain_cards_num = 6;
  if (has_remain_cards_num()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, this->remain_cards_num(), target);
  }

  // optional int32 banker_id = 7;
  if (has_banker_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(7, this->banker_id(), target);
  }

  // optional int32 banker_is_same_time = 8;
  if (has_banker_is_same_time()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(8, this->banker_is_same_time(), target);
  }

  // optional int32 cur_acting_player_id = 9;
  if (has_cur_acting_player_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(9, this->cur_acting_player_id(), target);
  }

  // optional int32 cur_action_id = 10;
  if (has_cur_action_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(10, this->cur_action_id(), target);
  }

  // repeated .gamer.protocol.PlayerCardsMsgProtocol player_cards = 11;
  for (int i = 0; i < this->player_cards_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        11, this->player_cards(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:gamer.protocol.GameStartMsgProtocol)
  return target;
}

int GameStartMsgProtocol::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 room_id = 1;
    if (has_room_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->room_id());
    }

    // required int32 room_owner_id = 2;
    if (has_room_owner_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->room_owner_id());
    }

    // optional int32 players_num = 3;
    if (has_players_num()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->players_num());
    }

    // optional int32 cur_round = 4;
    if (has_cur_round()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->cur_round());
    }

    // optional int32 total_round = 5;
    if (has_total_round()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->total_round());
    }

    // optional int32 remain_cards_num = 6;
    if (has_remain_cards_num()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->remain_cards_num());
    }

    // optional int32 banker_id = 7;
    if (has_banker_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->banker_id());
    }

    // optional int32 banker_is_same_time = 8;
    if (has_banker_is_same_time()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->banker_is_same_time());
    }

  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    // optional int32 cur_acting_player_id = 9;
    if (has_cur_acting_player_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->cur_acting_player_id());
    }

    // optional int32 cur_action_id = 10;
    if (has_cur_action_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->cur_action_id());
    }

  }
  // repeated .gamer.protocol.PlayerCardsMsgProtocol player_cards = 11;
  total_size += 1 * this->player_cards_size();
  for (int i = 0; i < this->player_cards_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->player_cards(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void GameStartMsgProtocol::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const GameStartMsgProtocol* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const GameStartMsgProtocol*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void GameStartMsgProtocol::MergeFrom(const GameStartMsgProtocol& from) {
  GOOGLE_CHECK_NE(&from, this);
  player_cards_.MergeFrom(from.player_cards_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_room_id()) {
      set_room_id(from.room_id());
    }
    if (from.has_room_owner_id()) {
      set_room_owner_id(from.room_owner_id());
    }
    if (from.has_players_num()) {
      set_players_num(from.players_num());
    }
    if (from.has_cur_round()) {
      set_cur_round(from.cur_round());
    }
    if (from.has_total_round()) {
      set_total_round(from.total_round());
    }
    if (from.has_remain_cards_num()) {
      set_remain_cards_num(from.remain_cards_num());
    }
    if (from.has_banker_id()) {
      set_banker_id(from.banker_id());
    }
    if (from.has_banker_is_same_time()) {
      set_banker_is_same_time(from.banker_is_same_time());
    }
  }
  if (from._has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (from.has_cur_acting_player_id()) {
      set_cur_acting_player_id(from.cur_acting_player_id());
    }
    if (from.has_cur_action_id()) {
      set_cur_action_id(from.cur_action_id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void GameStartMsgProtocol::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GameStartMsgProtocol::CopyFrom(const GameStartMsgProtocol& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GameStartMsgProtocol::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void GameStartMsgProtocol::Swap(GameStartMsgProtocol* other) {
  if (other != this) {
    std::swap(room_id_, other->room_id_);
    std::swap(room_owner_id_, other->room_owner_id_);
    std::swap(players_num_, other->players_num_);
    std::swap(cur_round_, other->cur_round_);
    std::swap(total_round_, other->total_round_);
    std::swap(remain_cards_num_, other->remain_cards_num_);
    std::swap(banker_id_, other->banker_id_);
    std::swap(banker_is_same_time_, other->banker_is_same_time_);
    std::swap(cur_acting_player_id_, other->cur_acting_player_id_);
    std::swap(cur_action_id_, other->cur_action_id_);
    player_cards_.Swap(&other->player_cards_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata GameStartMsgProtocol::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = GameStartMsgProtocol_descriptor_;
  metadata.reflection = GameStartMsgProtocol_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol
}  // namespace gamer

// @@protoc_insertion_point(global_scope)
